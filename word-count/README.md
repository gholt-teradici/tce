

# Word Count

## Build Instructions:

Navigate to project directory

    mkdir build
    cd build
    cmake ../
    make

## To run:

    ./word-count <filename>

eg.

    ./word-count ../tests/testFiles/ShortStory.txt

To run all tests:

    ./word-count

or use gtest_filter to run specific tests

    ./word-count --gtest_filter=TestWordExtractor.ExtractWordsWithPunctuation

## TDD
The google test framework was used https://github.com/google/googletest. No test fixtures were used as it was not needed. 

Two larger test files are included with their corresponding expected results file which consists of the top 10 word counts. These were generated using http://www.writewords.org.uk/word_count.asp.
In a case where this wasn't available, I would generate files using random words from a dictionary with random occurrences while storing the corresponding occurrences.

## Algorithm 

 - File is read and words are extracted and processed (punctuation
   removed, lowercase).
  - Words are inserted into a hash map that maps
   from word to count. STL's unordered_map is used.
   - We iterate through the map and create a min heap of size 10 to get the top 10 occurrences. STL's priority_queue is used.

#### Discussion:
The solution runs in average O(N) and uses O(N) space. Since the requirement was to return only the top 10 occurrences, optimization of the use of the min heap was not done. Note: This is assuming that words are average english words where the length of the word is << N.

The current implementation has each character read twice since the WordExtractor and WordOccurrenceContainer are decoupled. If we were to use our own implementation of a hash map or trie data structure we could read every character once instead. For example, in the case of a hash map, begin hashing as you read in characters rather than waiting to have the full word. In the case of a Trie, characters can be inserted one at a time.

