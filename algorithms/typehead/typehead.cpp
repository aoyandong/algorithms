/*
 * typehead.cpp
 *
 *  Created on: Apr 25, 2017
 *      Author: day
 */

#include "typehead.h"
using namespace std;

Trie::Trie(int _K){
	root = new TrieNode();
	K = _K;
}

void Trie::touch(string s){
	TrieNode* cur=root;
	stack<TrieNode*> stk;
	int n = s.length();
	for (int i=0; i<n; i++){
		if (cur->children[s[i]-'a']==nullptr) cur->children[s[i]-'a'] = new TrieNode();
		cur = cur->children[s[i]-'a'];
		stk.push(cur);
	}
	cur->is_end = true;
	cur->freq++;
	int freq = cur->freq;
	while (!stk.empty()){
		cur = stk.top();
		stk.pop();
		if (freq < cur->min_freq) return;
		if (cur->word_pos.find(s)!=cur->word_pos.end()){
			auto it = cur->word_pos[s];
			cur->top_words[freq-1].erase(it);
			cur->top_words[freq].push_front(s);
			cur->word_pos[s] = cur->top_words[freq].begin();
			if (cur->top_words[freq-1].size()==0){
				cur->top_words.erase(freq-1);
				if (cur->min_freq == freq-1) cur->min_freq++;
			}
		}
		else {
			if (cur->curK<K){
				cur->top_words[1].push_front(s);
				cur->word_pos[s] = cur->top_words[1].begin();
				cur->min_freq = 1;
				cur->curK++;
			}
			else {
				string out = cur->top_words[cur->min_freq].back();
				cur->top_words[cur->min_freq].pop_back();
				cur->word_pos.erase(out);
				cur->top_words[freq].push_front(s);
				cur->word_pos[s] = cur->top_words[freq].begin();
				if (cur->top_words[cur->min_freq].size()==0){
					cur->min_freq = freq;
					cur->top_words.erase(cur->min_freq);
				}
			}
		}
	}
}

int Trie::search(string s){
	TrieNode* cur=root;
	int n = s.length();
	for (int i=0; i<n; i++){
		if (cur->children[s[i]-'a']==nullptr) return 0;
		cur = cur->children[s[i]-'a'];
	}
	if (cur->is_end) return cur->freq;
	else return 0;
}

vector<string> Trie::topK(string s){
	vector<string> res;
	TrieNode* cur=root;
	int n = s.length();
	for (int i=0; i<n; i++){
		if (cur->children[s[i]-'a']==nullptr) return res;
		cur = cur->children[s[i]-'a'];
	}
	for (auto T:cur->word_pos){
		res.push_back(T.first);
	}
	return res;
}
