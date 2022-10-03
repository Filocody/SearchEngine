//
// Created by stigi on 08.04.2022.
//
#pragma once

#ifndef SEARCH_ENGINE_INVERTEDINDEX_H
#define SEARCH_ENGINE_INVERTEDINDEX_H

#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <algorithm>
#include <thread>
#include <mutex>

struct Entry
{
    size_t doc_id, count;

    bool operator == (const Entry& other) const {
        return (doc_id == other.doc_id && count == other.count);
    }
};

class InvertedIndex
{
public:
    InvertedIndex() = default;

    void UpdateDocumentBase(std::vector<std::string> input_docs); //update and fill documents
    static std::vector<std::string> GetWords (const std::string& input); // break string into separate words
    std::vector<Entry> GetWordCount(const std::string& word); // count

public:

    std::vector<std::vector<std::string>> docs;
    std::map<std::string, std::vector<Entry>> freq_dictionary;

};


#endif //SEARCH_ENGINE_INVERTEDINDEX_H
