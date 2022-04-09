//
// Created by stigi on 08.04.2022.
//

#include "converterJSON.h"

std::vector<std::string> ConverterJSON::GetConfigs()
{
    std::vector<std::string> configs;
    nlohmann::json dict;
    std::ifstream file("config.json");
    file >> dict;
    configs.push_back(dict["config"]["name"]);


}

std::vector<std::string> ConverterJSON::GetRequests()
{

}

int ConverterJSON::GetResponseLimits()
{

}

void ConverterJSON::PutAnswers(std::vector<std::vector<std::pair<int, float>>> answers)
{

}




