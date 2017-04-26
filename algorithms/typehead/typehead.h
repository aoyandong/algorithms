/*
 * typehead.h
 *
 *  Created on: Apr 25, 2017
 *      Author: day
 */

#ifndef TYPEHEAD_TYPEHEAD_H_
#define TYPEHEAD_TYPEHEAD_H_

#include "../everything.h"
using namespace std;

struct TrieNode{
	bool is_end;
	int freq; //if current node is a word, store its frequency
	vector<TrieNode*> children;
	unordered_map<int,list<string>> top_words; //K words in total
	unordered_map<string, list<string>::iterator> word_pos;
	int min_freq;
	int curK;
	TrieNode(): is_end(false), freq(0), min_freq(0), curK(0) {
		children = vector<TrieNode*>(26, nullptr);
	}
};

class Trie{
private:
	TrieNode* root;
	int K;
public:
	Trie(int _K=5);
	void touch(string s);
	int search(string s);
	vector<string> topK(string prefix);
};


#endif /* TYPEHEAD_TYPEHEAD_H_ */
