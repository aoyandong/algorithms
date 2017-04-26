/*
 * typehead_main.cpp
 *
 *  Created on: Apr 25, 2017
 *      Author: day
 */

#include "typehead.h"

int main(){
	Trie mytrie(3);
	mytrie.touch("amazon");
	mytrie.touch("amazing");
	mytrie.touch("amani");
	mytrie.touch("amazon");
	mytrie.touch("amazing");
	mytrie.touch("amigo");
	mytrie.touch("apache");
	mytrie.touch("apple");
	mytrie.touch("apple");
	mytrie.touch("amanda");
	mytrie.touch("amanda");
	vector<string> test = mytrie.topK("a");
	for (auto t:test) cout<<t<<' ';
	cout<<endl;
	cout<<mytrie.search("amazing")<<endl;
	return(0);
}

