#include "StatsCollector.h"

using namespace std;


/**
 * Load data from the file into a vector of char type
 * @param fileName : input file
 * @return the vector of char type loaded with file data
 */
std::vector<char> StatsCollector::loadDataIntoVector(string fileName) {
    vector<char> fileData = {};
    char ch;

    ifstream fin;
    fin.open(fileName.c_str(), ios::binary);

    if(!fin) {
        cout << "unable to open file\n";
        exit(1);
    }

    while (fin.get(ch)){
        fileData.push_back(ch);
    }

    fin.close();
    return fileData;
}


/**
 * Count the frequency of each character appeared in the file
 * @param fileData : the vector of type char format of original file data
 * @return the vector stats of charSet type
 */
vector<charSet>  StatsCollector::getStatsFromFileData(std::vector<char> fileData) {
    vector<charSet> stats = {};
    int index = 0;
    for(char i : fileData){
        index = findChar(stats, i);
        if (index == -1){
            stats.push_back(charSet{i, 1});
        }
        else {
            stats.at(index).frequency++;
        }
    }
    return stats;
}


/**
 * Check if the character has been marked
 * @param stats : a vector of type charSet used to mark the frequency of each saved character
 * @param ch : the new character read from the file
 * @return -1 if the char does not exist and return the index of the char if it exists
 */
int StatsCollector::findChar(vector<charSet> stats, char ch) {
    int index = -1;
    int i = 0;
    for (charSet set : stats) {
        if (set.ch == ch) {
            index = i;
            break;
        }
        i++;
    }
    return index;
}


/**
 * Test use: print stats data
 * @param stats : vector to save freq of each char
 */
void StatsCollector::print(vector<charSet> stats){
    for (charSet set : stats){
        cout << set.ch << " " << set.frequency << endl;
    }
}
