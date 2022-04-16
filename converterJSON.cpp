//
// Created by stigi on 08.04.2022.
//

#include "converterJSON.h"

std::vector<std::string> ConverterJSON::GetTextDocuments() // getting texts from text documents using config.json data
{
    std::vector<std::string> texts;
    nlohmann::json dict;
    std::ifstream s_file("../config.json");
    s_file >> dict;
    for (auto& file : dict["files"]) //"/resources/file001.txt"
    {
        std::string path = "..";
        path+=file;
        std::ifstream t_file(path);
        std::stringstream buffer;
        buffer << t_file.rdbuf();
        texts.push_back(buffer.str());
        t_file.close();
    }
    return texts;

}

std::vector<std::string> ConverterJSON::GetRequests() // getting requests data from requests.json
{
    std::vector<std::string> requests;
    nlohmann::json dict;
    std::ifstream s_file("../request.json");
    s_file >> dict;
    for (auto& request : dict["requests"])
    {
        requests.push_back(request);
    }
    return requests;
}

int ConverterJSON::GetResponseLimits() // getting number of responses from config.json
{
    nlohmann::json dict;
    std::ifstream file("../config.json");
    file >> dict;
    return dict["config"]["max_responses"];
}

void ConverterJSON::PutAnswers(std::vector<std::vector<std::pair<int, float>>> answers)
{
    nlohmann::ordered_json result;
    int i = 1;
    for(auto& answer : answers) {

        std::string str = "request";
        char buff[4];
        std::sprintf(buff,"%.3i", i);
        str += buff;

        result["answers"][str]["result"] = !answer.empty();
        if (answer.capacity() > 1) {
            int j = 0;
            for (auto &it : answer) {
                result["answers"][str]["relevance"][j].emplace("docid", it.first);
                result["answers"][str]["relevance"][j].emplace("rank", it.second);
                ++j;
            }
        } else if (!answer.empty()) {
            result["answers"][str]["docid"] = answer[0].first;
            result["answers"][str]["rank"] = answer[0].second;
        }
        ++i;
    }

    std::ofstream output("../answers.json");
    output << std::setw(4) << result;
    output.close();
}




