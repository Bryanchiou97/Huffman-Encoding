#include <queue>
#include "HuffmanTree.h"
#include <stdio.h>
using namespace std;


/**
 * Construct the Huffman Tree with min heap
 * @param stats : vector used to store frequency of different symbols
 * @return root of the built tree
 */
MinHeapNode* HuffmanTree::HuffmanCodes(vector<charSet> stats) {
    // Build a Huffman Tree and return the root of the tree
    // ...
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> mypq; 
	for (int i = 0; i < stats.size(); i++) {
		MinHeapNode* temp = new MinHeapNode(stats[i].ch, stats[i].frequency);
		mypq.push(temp);
	}
	for (int i = 0; i < stats.size() - 1; i++) {
		MinHeapNode* first = mypq.top();
		mypq.pop();
		MinHeapNode* second = mypq.top();
		mypq.pop();
		MinHeapNode* temp = new MinHeapNode('\0', (first->freq + second->freq));
		temp->left = first;
		temp->right = second;
		mypq.push(temp);
	}
	MinHeapNode* root = mypq.top();
	mypq.pop();
	return root;
	//sort
/*	int length = stats.size();
	for (int outer = 0; outer < length - 1; outer++) {
		for (int inner = 0; inner < length - outer - 1; inner++) {
			if (stats[inner].frequency >= stats[inner + 1].frequency) {
				//swap
				if (stats[inner].frequency > stats[inner + 1].frequency) {
					//swap
					char temp = stats[inner + 1].ch;
					int freq = stats[inner + 1].frequency;
					stats[inner + 1].ch = stats[inner].ch;
					stats[inner + 1].frequency = stats[inner].frequency;
					stats[inner].ch = temp;
					stats[inner].frequency = freq;
				}
				else {
					if (stats[inner].ch > stats[inner+1].ch) {
						//swap chars
						//char temp = stats[inner + 1].ch;
						//stats[inner + 1].ch = stats[inner].ch;
						//stats[inner].ch = temp;
						char temp = stats[inner + 1].ch;
						int freq = stats[inner + 1].frequency;
						stats[inner + 1].ch = stats[inner].ch;
						stats[inner + 1].frequency = stats[inner].frequency;
						stats[inner].ch = temp;
						stats[inner].frequency = freq;

					}
				}
			}	
		}
	}

	//push into another vector
	vector<MinHeapNode*> trees;// = { };
	for (int i = 0; i < stats.size(); i++) {
		MinHeapNode* temper = new MinHeapNode(stats[i].ch, stats[i].frequency);
		trees.push_back(temper);		
	}
	//for (int i = 0; i < trees.size(); i++) {
	//	cout << "trees: " << trees[i]->symbol << "    " << trees[i]->freq << endl;
	//}
	//start making the tree
	MinHeapNode * top;
//	cout << "length is: " << length << " and treesize is: " << trees.size() << endl;
	for (int i = 0; i < length - 1; i++) {
		MinHeapNode *temp = new MinHeapNode('*', (trees[0]->freq + trees[1]->freq));
		MinHeapNode* first = trees[0];
		MinHeapNode* second = trees[1];
		if (trees[0]->symbol == '*') {
			if(trees[1]->symbol == '*') { 
				int asciiOrder = trees[0]->left->symbol + trees[0]->right->symbol;
				int asciiOrder1 = trees[1]->left->symbol + trees[1]->right->symbol;
				if (asciiOrder > asciiOrder1) {
					first = trees[1];
					second = trees[0];
				}
			}
			else {
				first = trees[1];
				second = trees[0];
			}
		}
		temp->left = first;
		temp->right = second;
		trees.erase(trees.begin(), trees.begin()+2);
		int runningSize = (int)trees.size();
		for (int j = 0; j < runningSize; j++) {
//			cout << "vector size:  " << runningSize << "counter: " << j << endl; 
			if (temp->freq <= trees[j]->freq) {
				if (temp->freq < trees[j]->freq) {
					trees.insert(trees.begin()+j, temp);
					break;
				}
				else {
					if (trees[j]->symbol == '*') {
						//do nothing
						if (j == (runningSize - 1)) 
							trees.push_back(temp);
					}
					else {
						trees.insert(trees.begin()+j, temp);
						break;
					}
				}
			}
			else {
				if (j == (runningSize - 1) && temp->freq > trees[j]->freq) {
					trees.push_back(temp);
				}
			}
			//if (j == (runningSize - 1) && temp->freq > trees[j]->freq) {
			//	trees.push_back(temp);
			//}
		}
		top = temp;
	}	
	return top;*/
}


/**
*  Below are methods that can help you for debugging
*/

/**
 * Test use: print the string format of codes for each symbol
 * @param root : root node of the tree
 * @param str : placeholder used to concatenate chars
 */
void HuffmanTree::printCodes(MinHeapNode *root, std::string str) {
    if (!root)
        return;

    if (root->symbol != '\0'){
        cout << root->symbol << ": " << str << "\n";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}


/**
 * Test use: print the info about each leaf node
 * @param leaf : leaf node which contains a symbol
 * @param code : huffman codes in string format
 */
void HuffmanTree::printLeaves(MinHeapNode *leaf, string code) {
    string symbol;
    if (leaf->symbol == '\n'){
        symbol = "new line";
    }
    else {
        symbol = leaf->symbol;
    }
    cout << "\"" << symbol << "\", freq:" << leaf->freq
         << ", level:"
         << code.length() << ": " << code << endl;
}
