#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool wild_card(string s, string p){
	int ns=s.length(), np=p.length();
	int is=0, ip=0, star=-1, prev=-1;
	while (is<ns){
		if (ip<np && (s[is]==p[ip] || p[ip]=='.')) { is++; ip++; }
		else if (ip<np && p[ip]=='*'){
			star = ip;
			prev = is;
			ip++;
		}
		else {
			if (star==-1) return false;
			ip = star+1;
			is = prev+1;
			prev++;
		}
	}
	while(ip<np && p[ip]=='*') ip++;
	return ip==np;
}
/*
int main(){
	string s, p;
	while (true){
		cout<<"give a word: ";
		cin>>s;
		cout<<"give a pattern: ";
		cin>>p;
		if (s=="n") break;
		if (wild_card(s,p)) cout<<"good"<<endl;
		else cout<<"bad"<<endl;
	}
	return 0;
}
*/
