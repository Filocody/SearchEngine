//
// Created by stigi on 08.04.2022.
//

#include "InvertedIndex.h"
#include <sstream>

void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs)
{
    for (auto& doc : input_docs)
    {
        std::string str;
        std::vector<std::string> words;
        std::stringstream ss;
        ss.str(doc);
        while(!ss.eof())
        {
            ss >> str;
            words.push_back(str);
        }
        docs.push_back(words);
    }
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string &word)
{
    std::vector<Entry> word_count;
    size_t doc_id = 0;
    for (auto& doc : docs)
    {
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

    freq_dictionary.insert(std::pair<std::string, std::vector<Entry>>(word, word_count));

    return word_count;
}