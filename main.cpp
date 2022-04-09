#include <iostream>
#include "converterJSON.h"
#include "InvertedIndex.h"

int main() {
    std::vector<std::string> str = {{"milk salt cat"}, {"john kits walk"}, {"milk milk a b milk d"}};
    std::vector<Entry> word_count;
    std::vector<std::string> words = {"milk", "salt"};
    InvertedIndex idx;
    idx.UpdateDocumentBase(str);
    //
    for (auto& word : words) {
        word_count = idx.GetWordCount(word);
    }

    for (auto& it : idx.freq_dictionary)
    {
        std::cout <<it.first << " ";
        for (auto& count : it.second)
        {
            std::cout <<"{" << count.doc_id <<", " << count.count <<"} ";
        }
        std::cout << std::endl;
    }



    return 0;
}
