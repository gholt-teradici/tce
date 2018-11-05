//
// Created by Parsa Mohammadi on 2018-11-03.
//

#include <gtest/gtest.h>
#include "../src/WordOccurrenceContainer.hpp"


TEST (TestWordOccurrenceContainer, Smoke){
    WordOccurrenceContainer data;
    constexpr int NUM_OF_TOP = 1; //number of top occurrences

    data.insert("word");
    data.insert("word");
    data.insert("nottop");
    std::vector<std::pair<std::string, unsigned int>> v = data.getTopOccurrences(NUM_OF_TOP);

    ASSERT_EQ(v.size(), NUM_OF_TOP);
    ASSERT_EQ(v[0].first, "word");
    ASSERT_EQ(v[0].second, 2);

}

TEST (TestWordOccurrenceContainer, MultipleWords){
    WordOccurrenceContainer data;
    constexpr int NUM_OF_TOP = 3;

    for(int i = 0 ; i < 10; i++)
        data.insert("ten");
    for(int i = 0 ; i < 9; i++)
        data.insert("nine");
    for(int i = 0 ; i < 4; i++)
        data.insert("four");

    std::vector<std::pair<std::string, unsigned int>> v = data.getTopOccurrences(NUM_OF_TOP);

    ASSERT_EQ(v.size(), NUM_OF_TOP);

    ASSERT_EQ(v[0].first, "ten");
    ASSERT_EQ(v[0].second, 10);

    ASSERT_EQ(v[1].first, "nine");
    ASSERT_EQ(v[1].second, 9);

    ASSERT_EQ(v[2].first, "four");
    ASSERT_EQ(v[2].second, 4);

}

TEST (TestWordOccurrenceContainer, NumTopOccurencesGreaterThanNumWords){
    WordOccurrenceContainer data;
    constexpr int NUM_OF_TOP = 6;

    for(int i = 0 ; i < 9; i++)
        data.insert("nine");
    for(int i = 0 ; i < 4; i++)
        data.insert("four");

    std::vector<std::pair<std::string, unsigned int>> v = data.getTopOccurrences(NUM_OF_TOP);

    ASSERT_EQ(v.size(), 2);

    ASSERT_EQ(v[0].first, "nine");
    ASSERT_EQ(v[0].second, 9);

    ASSERT_EQ(v[1].first, "four");
    ASSERT_EQ(v[1].second, 4);

}