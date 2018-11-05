//
// Created by Parsa Mohammadi on 2018-11-04.
//

#include <iostream>
#include "WordCounter.hpp"

using namespace std;

WordCounter::WordCounter(const std::string &fileName) {
    m_wordExtractor = make_unique<WordExtractor>(fileName);
}

WordCounter::~WordCounter() {}

std::vector<std::pair<std::string, unsigned int>> WordCounter::getTopTenOccurrences() {
    string word;
    word = m_wordExtractor->extractNextWord();
    while (!word.empty()){
        m_wordContainer.insert(word);
        word = m_wordExtractor->extractNextWord();
    }

    m_topTenCache = m_wordContainer.getTopOccurrences(10);
    return m_topTenCache;
}

void WordCounter::printTopTenOccurrences() {
    if (m_topTenCache.empty()){
        getTopTenOccurrences();
    }
    for (auto ele: m_topTenCache){
        cout << ele.first << ": " << ele.second << endl;
    }

}