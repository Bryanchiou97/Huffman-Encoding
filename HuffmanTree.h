#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H

#include "StatsCollector.h"

// Huffman Tree node
typedef struct MinHeapNode{
    char symbol;
    unsigned int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char symbol, unsigned freq){
        left = right = nullptr;
        this->symbol = symbol;
        this->freq = freq;
    }
}MinHeapNode;

struct compare
{
    bool operator()(MinHeapNode* left, MinHeapNode* right)
    {
        if (left->freq > right->freq) 
		return true;
	else if (left->freq == right->freq) 
		return (left->symbol > right->symbol);
	return false;
    }
};

class HuffmanTree {
public:
    // To implement
    MinHeapNode* HuffmanCodes(std::vector<charSet> stats);
    // Test use
    void printCodes(MinHeapNode* root, std::string str);
    void printLeaves(MinHeapNode* leaf, std::string code);
};


#endif //HUFFMAN_HUFFMANTREE_H
