//
// Created by Parsa Mohammadi on 2018-11-03.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../src/WordExtractor.hpp"

#define TEST_FILE "testFile.txt"

void createFile(std::string s){
    std::ofstream fout(TEST_FILE);
    fout << s;
    fout.close();
}

TEST (TestWordExtractor, ExtractSingleWord){
    createFile("SingleWord");

    WordExtractor wordExtractor(TEST_FILE);

    std::string extractedWord;
    extractedWord = wordExtractor.extractNextWord();

    ASSERT_EQ(extractedWord, "singleword");
}

TEST (TestWordExtractor, ExtractWordsInSentence){
    createFile("Multiple words here.");

    WordExtractor wordExtractor(TEST_FILE);

    std::string extractedWord;

    extractedWord = wordExtractor.extractNextWord();
    ASSERT_EQ(extractedWord, "multiple");

    extractedWord = wordExtractor.extractNextWord();
    ASSERT_EQ(extractedWord, "words");

    extractedWord = wordExtractor.extractNextWord();
    ASSERT_EQ(extractedWord, "here");
}

TEST (TestWordExtractor, ExtractWordsWithPunctuation){
    createFile("Don't would'nt.It's!?");
    WordExtractor wordExtractor(TEST_FILE);

    std::string extractedWord;

    extractedWord = wordExtractor.extractNextWord();
    ASSERT_EQ(extractedWord, "dont");

    extractedWord = wordExtractor.extractNextWord();
    ASSERT_EQ(extractedWord, "wouldnt");

    extractedWord = wordExtractor.extractNextWord();
    ASSERT_EQ(extractedWord, "its");

    extractedWord = wordExtractor.extractNextWord();
    ASSERT_EQ(extractedWord, "");
}

TEST (TestWordExtractor, EmptyFile){
    createFile("");

    WordExtractor wordExtractor(TEST_FILE);

    std::string extractedWord;

    extractedWord = wordExtractor.extractNextWord();
    ASSERT_EQ(extractedWord, "");
}

TEST (TestWordExtractor, CantOpenFile){
    try {
        WordExtractor wordExtractor("doesntExist.txt");
    } catch (std::invalid_argument) {
        //pass
        return;
    }

    FAIL();
}

