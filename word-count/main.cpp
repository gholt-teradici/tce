#include <gtest/gtest.h>
#include "src/WordCounter.hpp"

int printTopTenWords(std::string fileName);

int main(int argc, char* argv[]) {
    if(argc > 1){
        std::string s_argv = argv[1];
        // if a text file is given
        if (s_argv.find(".txt") != std::string::npos){
            return printTopTenWords(s_argv);
        }
    }

    // else run tests
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

int printTopTenWords(std::string fileName){
    try {
        WordCounter wordCounter(fileName);
        wordCounter.printTopTenOccurrences();
    } catch (...) {
        return 1;
    }
    return 0;
}