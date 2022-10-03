#include "SearchServer.h"

std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string> &queries_input) {

    std::vector<std::vector<RelativeIndex>> result;

    for (auto& input : queries_input)
    {
        std::vector<std::string> words = _index.GetWords(input);
        std::set<std::string> unique_words;
        std::map<size_t, float> dict;
        bool found = false;
        std::vector<RelativeIndex> idx;

        for(auto& word : words) {
            unique_words.insert(word);
        }

        for(auto& word : unique_words) {
            auto it = _index.freq_dictionary.find(word); //finding the vector of entries of the word
            if(it != _index.freq_dictionary.end()) {
                found = true;
                for(auto& entry : it->second) {
                    dict[entry.doc_id] += entry.count;  //adding entries of different words together so getting absolute relevance of the request
                }
            }
        }
        if(found) {
            auto pt = std::max_element(dict.begin(), dict.end(), [](const auto& x, const auto& y){
                return x.second < y.second; //finding the highest value of absolute relevance
            });
            float max = pt->second;
            for(auto& entry : dict) {
                entry.second /= max; // turning absolute relevance into relevant
            }

            std::vector<std::pair<size_t , float>> s;  // The new (temporary) container.
            for(auto i : dict) {
                s.emplace_back(i.first, i.second);
            }
            std::sort(s.begin(), s.end(), [](auto& x, auto& y){
                return x.second != y.second ? x.second > y.second : x.first < y.first;
            });

            int i = 0;
            for(auto entry = s.begin(); entry != s.end() && i < ResponseLimit; entry++) {
                idx.push_back(RelativeIndex(entry->first, entry->second));
                i++;
            }
            result.push_back(idx);

        } else result.push_back(std::vector<RelativeIndex>{});
    }

    return result;
}

