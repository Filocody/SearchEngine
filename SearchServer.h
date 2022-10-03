#ifndef SEARCH_ENGINE_SEARCHSERVER_H
#define SEARCH_ENGINE_SEARCHSERVER_H

#include "InvertedIndex.h"
#include <set>
#include <algorithm>

struct RelativeIndex{
    size_t doc_id;
    float rank;

    RelativeIndex(size_t _id, float _rank) : doc_id(_id), rank(_rank) {};

    bool operator ==(const RelativeIndex& other) const {
        return (doc_id == other.doc_id && rank == other.rank);
    }
};
class SearchServer {
public:
    SearchServer(InvertedIndex& idx) : _index(idx){ };
/**
* Метод обработки поисковых запросов
* @param queries_input поисковые запросы взятые из файла
requests.json
* @return возвращает отсортированный список релевантных ответов для
заданных запросов
*/
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& queries_input);

    void setResponseLimit(int limit) { ResponseLimit = limit; }

private:
    int ResponseLimit = 5;
    InvertedIndex _index;
};




#endif //SEARCH_ENGINE_SEARCHSERVER_H
