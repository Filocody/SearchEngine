#include <iostream>
#include "converterJSON.h"
#include "InvertedIndex.h"
#include "SearchServer.h"
#include <chrono>


int main() {

    InvertedIndex idx;
    std::vector<std::string> texts = ConverterJSON::GetTextDocuments();
    std::vector<std::string> requests = ConverterJSON::GetRequests();
    int responseLimit = ConverterJSON::GetResponseLimits();

    // Get Start Time
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    idx.UpdateDocumentBase(texts);

    SearchServer search(idx);

    search.setResponseLimit(responseLimit);
    auto result = search.search(requests);

    std::vector<std::vector<std::pair<size_t, float>>> answers;

    for(auto& it : result) {
        std::vector<std::pair<size_t, float>> buff;
        buff.reserve(it.size());
        for(auto& i : it) {
            buff.emplace_back(i.doc_id, i.rank);
        }
        answers.push_back(buff);
    }

    ConverterJSON::PutAnswers(answers);

    // Get End Time
    auto end = std::chrono::system_clock::now();

    auto diff = std::chrono::duration_cast < std::chrono::microseconds > (end - start).count();
    std::cout << "Total Time Taken = " << diff/1000000 << " Seconds" << std::endl;
    std::cout <<"Answers are generated! Look what we found!" <<std::endl;

    return 0;
}
