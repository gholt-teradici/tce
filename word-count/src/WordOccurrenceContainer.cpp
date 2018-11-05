//
// Created by Parsa Mohammadi on 2018-11-03.
//

#include <iostream>
#include <stack>
#include "WordOccurrenceContainer.hpp"

using namespace std;

WordOccurrenceContainer::WordOccurrenceContainer() {}
WordOccurrenceContainer::~WordOccurrenceContainer() {}

void WordOccurrenceContainer::insert(const string& word) {
    auto map_itr = m_wordToCountMap.find(word);
    // if word doesn't exist in map
    if (map_itr == m_wordToCountMap.end()) {
        // insert into map
        m_wordToCountMap[word] = 1;
    }
    // else increase count
    else {
        map_itr->second += 1;
    }

}

vector<pair<string, unsigned int>> WordOccurrenceContainer::getTopOccurrences(const unsigned int& heapSize) {

    WordandCount data;
    priority_queue<WordandCount> minHeap;

    for (auto element : m_wordToCountMap){
        data.word = element.first;
        data.count = element.second;

        // heapSize corresponds to top n occurrences
        if (minHeap.size() == heapSize){
            // if heap is full and this word's count is larger
            // than the min, remove min and pop this word in.
            if(data.count > minHeap.top().count){
                minHeap.pop();
                minHeap.push(data);
            }
        }
        else {
            minHeap.push(data);
        }
    }

    // return vector with top n words in descending order
    stack<pair<string, unsigned int>> s;
    while (!minHeap.empty()){
        data = minHeap.top();
        s.push(make_pair(data.word, data.count));
        minHeap.pop();
    }
    vector<pair<string, unsigned int>> v;
    while (!s.empty()){
        v.emplace_back(s.top());
        s.pop();
    }
    return v;
}