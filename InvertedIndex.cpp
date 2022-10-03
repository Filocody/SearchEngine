//
// Created by stigi on 08.04.2022.
//

#include "InvertedIndex.h"

void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs)
{
    for (auto& doc : input_docs)
    {
        docs.push_back(GetWords(doc));
    }

    for (auto& doc : docs) {
        for (auto& word : doc) {
            auto search = freq_dictionary.find(word);
            if(search == freq_dictionary.end()) {
                freq_dictionary[word] = GetWordCount(word);
            }
        }
    }
}


std::vector<Entry> InvertedIndex::GetWordCount(const std::string &word)
{
    std::vector<Entry> word_count;
    size_t doc_id = 0;
//
////**********************************************************

//    int size = (int) docs.size();
//    std::thread threads[size];
//    std::mutex mutex;
//
//    for (auto& doc : docs) {
//        threads[doc_id] = std::thread ([&, doc_id] ()
//                {
//                    size_t count = 0;
//
//                    for (auto& _word : doc)
//                    {
//                        if (word == _word) count++;
//                    }
//
//                    if (count != 0)
//                    {
//                        Entry entry{doc_id, count};
//                        mutex.lock();
//                        word_count.push_back(entry);
//                        mutex.unlock();
//                    }
//                });
//        doc_id++;
//    }
//
//    for(auto& thread : threads) {
//        thread.join();
//    }

//**********************************************************
//
    for (auto& doc : docs) {
        size_t count = 0;

        for (auto& _word : doc)
        {
            if (word == _word) count++;
        }

        if (count != 0)
        {
            Entry entry{doc_id, count};
            word_count.push_back(entry);
        }

        doc_id++;
    }

//**********************************************************

    return word_count.empty() ? std::vector<Entry>{{}} : word_count;
}

std::vector<std::string> InvertedIndex::GetWords(const std::string& input) {
    std::string str;
    std::vector<std::string> words;
    std::stringstream ss;
    ss.str(input);
    while(!ss.eof())
    {
        ss >> str;
        std::for_each(str.begin(), str.end(), [](char& c){ c = ::tolower(c); });
        words.push_back(str);
    }

    return words;
}


