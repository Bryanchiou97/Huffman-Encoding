#ifndef HUFFMAN_STATSCOLLECTOR_H
#define HUFFMAN_STATSCOLLECTOR_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

struct charSet{
    char ch;
    int frequency; // times of character repeats
};

class StatsCollector{
public:
    std::vector<char> loadDataIntoVector(std::string fileName);
    int findChar(std::vector<charSet> stats, char ch);
    std::vector<charSet> getStatsFromFileData(std::vector<char> fileData);
    void print(std::vector<charSet> stats);
};

#endif //HUFFMAN_STATSCOLLECTOR_H
