//
// Created by Parsa Mohammadi on 2018-11-04.
//
#include <gtest/gtest.h>
#include <fstream>
#include "../src/WordCounter.hpp"

#define TEST_FILE_SHORT_STORY "../tests/testFiles/ShortStory.txt"
#define TEST_FILE_SHORT_STORY_ANSWER "../tests/testFiles/ShortStoryCounts.txt"

#define TEST_FILE_NEWS_ARTICLE "../tests/testFiles/NewsArticle.txt"
#define TEST_FILE_NEWS_ARTICLE_ANSWER "../tests/testFiles/NewsArticleCounts.txt"

using namespace std;

// Assumes test file is formatted properly.
vector<pair<string, unsigned int>> getTestFileAnswer(string fileName){
    vector<pair<string, unsigned int>> v;
    ifstream fin(fileName);
    if(!fin){
        cout << "Failed to open test file answers: " << fileName << endl;
        return v;
    }
    string word;
    int count;
    while (fin >> word){
        fin >> count;
        v.emplace_back(make_pair(word, count));
    }
    return v;

};

inline void testFile(const string& file, const string& fileAnswer){
    WordCounter wordCounter(file);

    vector<pair<string, unsigned int>> wordCountResult, wordCountExpected;
    wordCountResult = wordCounter.getTopTenOccurrences();

    wordCountExpected = getTestFileAnswer(fileAnswer);

    ASSERT_FALSE(wordCountExpected.empty());

    ASSERT_EQ(wordCountResult, wordCountExpected);
}

TEST (TestWordCounter, TestShortStoryFile){
    testFile(TEST_FILE_SHORT_STORY, TEST_FILE_SHORT_STORY_ANSWER);
}

TEST (TestWordCounter, TestNewsArticleFile){
    testFile(TEST_FILE_NEWS_ARTICLE, TEST_FILE_NEWS_ARTICLE_ANSWER);
}