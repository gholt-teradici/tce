//
// Created by Parsa Mohammadi on 2018-11-03.
//

#ifndef TERADICI_WORDEXTRACTOR_HPP
#define TERADICI_WORDEXTRACTOR_HPP


#include <string>
#include <fstream>

/**
 * @brief Class used to extract words from file that contains ASCII characters
 */
class WordExtractor {
public:
    /**
     * Opens file for reading.
     * @param fileName - File to be read.
     */
    WordExtractor(const std::string& fileName);
    /**
     * Closes file
     */
    ~WordExtractor();

    /**
     * @brief Extracts the next word. Ignores punctuation (eg. it's = its)
     * If multiple words are concatenated together with a character
     * like  hyphen(-) or underscore(_) it will count them as seperate words.
     * @return Extracted word.
     */
    std::string extractNextWord();

private:

    std::ifstream m_fin;
};


#endif //TERADICI_WORDEXTRACTOR_HPP
