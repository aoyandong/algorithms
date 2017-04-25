#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

void helper(string s, vector<string>& res, int pos){
	if (pos==s.length()){
		res.push_back(s);
		return;
	}
	for (int i=pos; i<s.length(); i++){
		if (i!=pos && s[i]==s[pos]) continue;
		swap(s[i],s[pos]);
		helper(s, res, pos+1);
	}
}


vector<string> permutation(string s){
	int n=s.length();
	sort(s.begin(),s.end());
	vector<string> res;
	helper(s, res, 0);
	return res;
}
