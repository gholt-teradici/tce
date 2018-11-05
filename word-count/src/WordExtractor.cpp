//
// Created by Parsa Mohammadi on 2018-11-03.
//

#include <iostream>
#include "WordExtractor.hpp"


WordExtractor::WordExtractor(std::string fileName) {
    fin.open(fileName);
    if (!fin){
        std::string err = "Error opening file: ";
        err = err + fileName + '\n';
        std::cerr << err;
        throw std::invalid_argument(err);
    }
}

WordExtractor::~WordExtractor() {
    if (fin.is_open()){
        fin.close();
    }
}

std::string WordExtractor::extractNextWord() {
    char c;
    std::string word;
    while (fin.peek() != std::char_traits<char>::eof()){
        fin.get(c);
        c = (char)tolower(c);
        if ((c >= 'a' && c <= 'z') || c == '\'') {
            if(c != '\''){  // ignore ' in words (eg. it's = its)
                word += c;
            }
        }
        else {
            if (!word.empty()){
                return word;
            }
            word.clear();
        }
    }
    return word;
}