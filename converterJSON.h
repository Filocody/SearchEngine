//
// Created by stigi on 08.04.2022.
//
#pragma once

#ifndef SEARCH_ENGINE_CONVERTERJSON_H
#define SEARCH_ENGINE_CONVERTERJSON_H

#include <vector>
#include <string>
#include "nlohmann/json.hpp"
#include <fstream>

class ConverterJSON
{
public:
    ConverterJSON() = default;

    std::vector<std::string> GetTextDocuments();
    std::vector<std::string> GetRequests();
    int GetResponseLimits();
    void PutAnswers(std::vector<std::vector<std::pair<int, float>>> answers);

};

#endif //SEARCH_ENGINE_CONVERTERJSON_H
