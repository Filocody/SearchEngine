#include "gtest/gtest.h"
#include "converterJSON.h"

auto* converter = new ConverterJSON();
std::vector<std::string> texts = {
        "London is a capital of Great Britain",
        "Eat an apple every day",
        "Past is a history",
        "Coding is an extremely difficult activity"
};
std::vector<std::string> requests = {
        "some words..",
        "some words..",
        "some words..",
        "some words.."
};
std::vector<std::vector<std::pair<int, float>>> answers = {
        {{2,0.99},{1, 0.85},{3, 0.74}},
        {{1, 0.53},{3, 0.22}},
        {{}},
        {{3, 0.12}}
};

TEST(TestConverterJSON, TestResponseLimits)
{
    ASSERT_EQ(converter->GetResponseLimits(),5);
}

TEST(TestConverterJSON, TestTextDocuments)
{
    ASSERT_EQ(converter->GetTextDocuments(),texts);
}

TEST(TestConverterJSON, TestRequests)
{
    ASSERT_EQ(converter->GetRequests(),requests);
}

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}