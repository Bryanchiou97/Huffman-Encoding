#ifndef HUFFMAN_DECOMPRESSOR_H
#define HUFFMAN_DECOMPRESSOR_H

#include "HuffmanTree.h"

using namespace std;
class Decompressor {
public:
    // Constructor

    Decompressor(string inFile, string outFile) {
    	this->inputFile = inFile;
	this->outputFile = outFile;
    }
    // Add methods that you need for decompressing
    void doWork();
    //void compareHeap(MinHeapNode * root);
    //bool compareNodes(MinHeapNode * left, MinHeapNode * right);
private:
    // Here goes any private members or methods 
	string inputFile;
	string outputFile;
};


#endif //HUFFMAN_DECOMPRESSOR_H
