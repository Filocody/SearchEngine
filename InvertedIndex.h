//
// Created by stigi on 08.04.2022.
//

#ifndef SEARCH_ENGINE_INVERTEDINDEX_H
#define SEARCH_ENGINE_INVERTEDINDEX_H

#include <vector>
#include <string>
#include <map>

struct Entry
{
    size_t doc_id, count;
};

class InvertedIndex
{
public:
    InvertedIndex() = default;
    void UpdateDocumentBase(std::vector<std::string> input_docs); //update and fill documents
    std::vector<Entry> GetWordCount(const std::string& word); // count
public:
    std::vector<std::vector<std::string>> docs;
    std::map<std::string, std::vector<Entry>> freq_dictionary;

};


#endif //SEARCH_ENGINE_INVERTEDINDEX_H
