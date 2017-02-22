#include "Decompressor.h"
#include <iostream>

using namespace std;

void Decompressor::doWork() {
	//now we can start decompressing.
	unsigned char temp;
	string str;
	//fstream myFile(inputFile, std::ios_base::in);
	vector<charSet> huffer;
	int ccCounter = 0;
	fstream fin(inputFile, fstream::in);
	while (fin >> noskipws >> temp) {
		char firstChar = temp;
		fin >> noskipws >> temp;
		if (firstChar == '0' && temp == '0') {
			fin >> noskipws >> temp;
			break;
		}
		string char1;
		char1.push_back((char)temp);
		while (fin >> noskipws >> temp) {
			if (temp > 47 && temp < 58)
				char1.push_back((char)temp);
			else
				break;
		}
		int howMany = std::stoi(char1,nullptr,10);
		ccCounter += howMany;
		huffer.push_back(charSet{firstChar, (howMany)});
	}
	int ddCounter = 0;
/*	for (int i = 0; i < huffer.size(); i++) {
		if (huffer[i].ch == '\n')
			newlineFreq = huffer[i].frequency;
	}
*/
	HuffmanTree hmt;
	MinHeapNode * huffmanTree = hmt.HuffmanCodes(huffer);
	MinHeapNode * root = huffmanTree;

	string compressed = "";
	int index1 = 0;
	string empty = "";
	while (fin >> noskipws >> temp) {
		unsigned char t = (temp&0xFF);
		if (ddCounter == ccCounter)
			break;
		for (int xx = 0; xx < 8; xx++) {
			if (ddCounter == ccCounter)
				break;
			int sss =(int)t >> (7-xx)&0x01;
			int going;
			if (xx != 7)
				going = (int)t >> 7-(xx+1)&0x01;

			if (sss == 0) {
				compressed.push_back('0');
				//new
				if (root->left != nullptr) {
					root = root->left;
					//index++;
				}
				else {
					//str += roots->ch;
					str.push_back(root->symbol);
			//		if(root->symbol == '\n') {
			//			newlineCounter++;
			//		}
					//write word to the file	
					root = huffmanTree->left;
					ddCounter++;
				}
			}
			else {
				compressed.push_back('1');
				if (root->right != nullptr) {
					root = root->right;
				}
				else {
					str.push_back(root->symbol);
			//		if(root->symbol == '\n' && going == 0) {
			//			newlineCounter++;
			//		}
					root = huffmanTree->right;
					ddCounter++;
				}

			}
		}
	}
	ofstream out(outputFile);
	out << str;
	out.close();
	
}

