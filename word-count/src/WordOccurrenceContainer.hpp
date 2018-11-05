//
// Created by Parsa Mohammadi on 2018-11-03.
//

#ifndef TERADICI_WORDOCCURENCECONTAINER_HPP
#define TERADICI_WORDOCCURENCECONTAINER_HPP


#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

/**
 * @brief Container used to keep counts of word occurrences
 */
class WordOccurrenceContainer {
public:

    WordOccurrenceContainer();
    ~WordOccurrenceContainer();

    /**
     * @brief Inserts a word into the WordOccurrenceContainer
     * @param word - The word that will be inserted.
     */
    void insert(const std::string& word);

    /**
     * @brief Gets the top n words that occur the most
     * @param n - top n words that occur.
     * @return Vector of pairs where first is the word and second is the count.
     */
    std::vector <std::pair<std::string, unsigned int>> getTopOccurrences(const unsigned int& n);

private:
    /**
     * @brief structure for word and count pair.
     * Overloads < operator to use STL priority queue as a min heap rather than a max heap
     */
    struct WordandCount{
        std::string word;
        unsigned int count;

        bool operator<(const WordandCount& rhs) const
        {
            return count > rhs.count;
        }
    };
    /** HashMap that maps word to count*/
    std::unordered_map<std::string, unsigned int> m_wordToCountMap;
};


#endif //TERADICI_WORDOCCURENCECONTAINER_HPP
