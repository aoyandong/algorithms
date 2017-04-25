#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TrieNode{
	vector<TrieNode*> children;
	bool is_end;
	int len;
	TrieNode(){
		children = vector<TrieNode*>(26, nullptr);
		is_end = false;
		len = 0;
	}
};

class Trie{
private:
	TrieNode* root;
public:
	Trie(){ root = new TrieNode(); }
	void add(string s){
		int n = s.length();
		TrieNode* cur=root;
		for (int i=0; i<n; i++){
			cur->len = max(cur->len, n-i);
			if (cur->children[s[i]-'a']==nullptr) cur->children[s[i]-'a'] = new TrieNode();
			cur = cur->children[s[i]-'a'];
		}
		cur->is_end = true;
	}

	bool search(string s){
		return search_helper(s, root);
	}

	bool search_wc(string s){
		int n = s.length(), len = 0;
		if (n==0) return false;
		for (auto c:s)
			if (c!='*') len++;
		return search_helper_wc(s, root, 0, len);
	}

	bool search_wc_withmatchedstring(string s, string& p){
		int n = s.length(), len = 0;
		if (n==0) return false;
		for (auto c:s)
			if (c!='*') len++;
		return search_helper_wc_withmatchedstring(s, root, 0, len, p);
	}

private:
	bool search_helper(string& s, TrieNode* cur){
		int n = s.length();
		for (int i=0; i<n; i++){
			if (cur->children[s[i]-'a']==nullptr) return false;
			cur = cur->children[s[i]-'a'];
		}
		return cur->is_end;
	}

	bool search_helper_wc(string& s, TrieNode* cur, int pos, int len){
		int n = s.length();
		if (cur->len < len) return false;
		for (int i=pos; i<n; i++){
			if (s[i]!='.' && s[i]!='*'){
				if (cur->children[s[i]-'a']==nullptr) return false;
				cur = cur->children[s[i]-'a'];
				len--;
			}
			else if (s[i]=='.'){
				for (int j=0; j<26; j++){
					if (cur->children[j]==nullptr) continue;
					if (search_helper_wc(s, cur->children[j], i+1, len-1)) return true;
				}
				return false;
			}
			else {
				while (i<n && s[i]=='*') i++; //skip stars
				if (i==n) return true;
				//search * match 0 char
				if (search_helper_wc(s, cur, i, len)) return true;
				// skip 1 char, recursively search *xxxx within the skipped char trie
				for (int j=0; j<26; j++){
					if (cur->children[j]==nullptr) continue;
					if (search_helper_wc(s,cur->children[j],i-1,len)) return true;
				}
				return false;
			}
		}
		return cur->is_end;
	}

	bool search_helper_wc_withmatchedstring(string& s, TrieNode* cur, int pos, int len, string& p){
		int n = s.length();
		if (cur->len < len) return false;
		for (int i=pos; i<n; i++){
			if (s[i]!='.' && s[i]!='*'){
				if (cur->children[s[i]-'a']==nullptr) return false;
				cur = cur->children[s[i]-'a'];
				p.push_back(s[i]);
				len--;
			}
			else if (s[i]=='.'){
				for (int j=0; j<26; j++){
					if (cur->children[j]==nullptr) continue;
					p.push_back(j+'a');
					if (search_helper_wc_withmatchedstring(s, cur->children[j], i+1, len-1, p)) return true;
					p.pop_back();
				}
				return false;
			}
			else {
				while (i<n && s[i]=='*') i++; //skip stars
				if (i==n) {
					while (!cur->is_end){
						for (int j=0; j<26; j++){
							if (cur->children[j]==nullptr) continue;
							cur = cur->children[j];
							p.push_back(j+'a');
						}
					}
					return true;
				}
				//search * match 0 char
				int memo = p.length();
				if (search_helper_wc_withmatchedstring(s, cur, i, len, p)) return true;
				p = p.substr(0,memo);

				// skip 1 char, recursively search *xxxx within the skipped char trie
				for (int j=0; j<26; j++){
					if (cur->children[j]==nullptr) continue;
					p.push_back(j+'a');
					if (search_helper_wc_withmatchedstring(s,cur->children[j],i-1,len,p)) return true;
					p.pop_back();
				}
				return false;
			}
		}
		return cur->is_end;
	}
};
/*
int main(){
	Trie tr;
	vector<string> words({"apple","bear","banana","bravo","bazinga","appreciate",
		"apprecot","blizzard","keke"});
	for (auto w:words) tr.add(w);
	string s;
	while (true){
		cout<<"give a word: ";
		cin>>s;
		if (s=="n") break;
		string p;
		if (tr.search_wc_withmatchedstring(s,p)) cout<<p<<endl;
		//if (tr.search_wc(s)) cout<<"In"<<endl;
		else cout<<"Not in"<<endl;
	}
	return 0;
}

*/
