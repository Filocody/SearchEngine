#include <iostream>
#include "converterJSON.h"
#include "InvertedIndex.h"



int main() {

    auto* converter = new ConverterJSON;
    std::vector<std::vector<std::pair<int, float>>> answers = {
            {{2,0.99},{1, 0.85},{3, 0.74}},
            {{1, 0.53},{3, 0.22}},
            {{}},
            {{3, 0.12}}
    };

    converter->PutAnswers(answers);

    return 0;
}
