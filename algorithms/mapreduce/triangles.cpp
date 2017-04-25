/*
 * triangles.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: day
 */
#include "everything.h"
using namespace std;

void mapper(unordered_map<int, vector<int>>& data, multiset<long>& triples){
	long offset1 = 1000000; // optimal: list length^2
	long offset2 = 1000; // optimal: list length
	for (auto d:data){
		int id = d.first;
		if (d.second.size()<2) continue;
		vector<int> tmp(3,0);
		//cout<<id<<endl;
		for (int i=0; i<d.second.size(); i++){
			for (int j=i+1; j<d.second.size(); j++){
				tmp[0] = id;
				tmp[1] = d.second[i];
				tmp[2] = d.second[j];
				sort(tmp.begin(),tmp.end());
				//for (auto t:tmp) cout<<t<<' ';
				//cout<<endl;
				long signature = offset1*tmp[0] + offset2*tmp[1] + tmp[2];
				triples.insert(signature);
			}
		}
	}
}

void reducer(multiset<long> &triples, multiset<vector<int>>& res){
	int cnt=0;
	long cur;
	long offset1 = 1000000;
	long offset2 = 1000;
	//the key value pair emmitted by mapper will be sharded by mod offset1
	for (auto t:triples){
		if (cnt==0 || cur!=t){
			cur = t;
			cnt = 1;
		}
		else cnt++;
		if (cnt==3) {
			int id1 = cur/offset1;
			cur%=offset1;
			int id2 = cur/offset2;
			cur%=offset2;
			int id3 = cur;
			res.insert(vector<int>({id1,id2,id3}));
			res.insert(vector<int>({id2,id1,id3}));
			res.insert(vector<int>({id3,id1,id2}));
		}
	}
}
/*
int main(){
	ifstream in;
	in.open("inputs/friends.txt");
	unordered_map<int, vector<int>> data;
	string s;
	while (getline(in,s)){
		istringstream sin(s);
		int id, cur;
		sin>>id;
		vector<int> tmp;
		while (sin>>cur){
			tmp.push_back(cur);
		}
		data[id] = tmp;
	}
	for (auto d:data){
		cout<<d.first<<": ";
		for (auto j:d.second) cout<<j<<' ';
		cout<<endl;
	}
	cout<<endl;

	multiset<long> triples;
	mapper(data,triples);

	multiset<vector<int>> res;
	reducer(triples,res);

	//cout<<triples.size()<<endl;
	//for (auto i:triples) cout<<i<<' ';
	//cout<<endl;

	for (auto r:res){
		for (auto i:r){
			cout<<i<<' ';
		}
		cout<<endl;
	}
	return 0;
}
*/
