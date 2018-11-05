//
// Created by Parsa Mohammadi on 2018-11-04.
//

#ifndef TERADICI_WORDCOUNTER_HPP
#define TERADICI_WORDCOUNTER_HPP


#include <string>
#include "WordExtractor.hpp"
#include "WordOccurrenceContainer.hpp"

/**
 * @brief Given a file that contains ASCII, counts word occurrences.
 * Can return top ten words that occur in the file.
 */
class WordCounter {
public:
    /**
     * Constructs  a WordCounter
     * @param fileName - File to be read
     * @throws throws std::invalid_argument if file cannot be opened
     */
    WordCounter(const std::string& fileName);
    ~WordCounter();

    std::vector<std::pair<std::string, int>> getTopTenOccurrences();
    void printTopTenOccurrences();

private:
    /** object used to extract words from file*/
    std::unique_ptr<WordExtractor> m_wordExtractor;

    /** Container used to keep track of occurrences of words*/
    WordOccurrenceContainer m_wordContainer;

    /** */
    std::vector<std::pair<std::string, int>> m_topTenCache;

};


#endif //TERADICI_WORDCOUNTER_HPP
