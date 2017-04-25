/*
 * overlap_rectangle.cpp
 *
 *  Created on: Apr 25, 2017
 *      Author: aoyan
 */

#include "everything.h"
using namespace std;

struct comp_x2{
	bool operator()(vector<int>& a, vector<int>& b){
		return a[2]>b[2];
	}
};

struct comp_y2{
	bool operator()(vector<int>& a, vector<int>& b){
		return a[3]>b[3];
	}
};

static bool sort_x1(vector<int>& a, vector<int>& b){
	return a[0]<b[0];
}

static bool sort_y1(vector<int>& a, vector<int>& b){
	return a[1]<b[1];
}

int calc(multiset<vector<int>>& inpq, pair<int,int>& ret){
	priority_queue<vector<int>, vector<vector<int>>, comp_y2> pqy;
	vector<vector<int>> rects;
	for (auto i:inpq) rects.push_back(i);
	sort(rects.begin(),rects.end(), sort_y1);
	int best=0, n=rects.size();
	for (int i=0; i<n; i++){
		while (!pqy.empty() && pqy.top()[3]<rects[i][1]) pqy.pop();
		pqy.push(rects[i]);
		if (int(pqy.size())>best){
			best = pqy.size();
			ret.second = rects[i][1];
		}
	}
	return best;
}

pair<int,int> overlap_rectangle(vector<vector<int>>& rects, int& best){
	int n=rects.size();
	best = 0;
	pair<int,int> res;
	priority_queue<vector<int>, vector<vector<int>>, comp_x2> pqx;
	multiset<vector<int>> in_pq;

	sort(rects.begin(), rects.end(), sort_x1);
	for (int i=0; i<=n; i++){
		if (i==n || (!pqx.empty() && pqx.top()[2]<rects[i][0])){
			if (int(pqx.size())>best){
				pair<int,int> tmp;
				tmp.first = rects[i-1][0];
				int cur = calc(in_pq, tmp);
				if (cur>best){
					best = cur;
					res = tmp;
				}
			}
			if (i==n) break;
			while (!pqx.empty() && pqx.top()[2]<rects[i][0]){
				vector<int> tmp=pqx.top();
				in_pq.erase(in_pq.find(tmp));
				pqx.pop();
			}
		}
		pqx.push(rects[i]);
		in_pq.insert(rects[i]);
	}
	return res;
}

int main(){
	vector<vector<int>> rects;
	rects.push_back(vector<int>({0,4,8,7}));
	rects.push_back(vector<int>({2,0,5,6}));
	rects.push_back(vector<int>({3,1,6,2}));
	rects.push_back(vector<int>({7,1,9,2}));
	rects.push_back(vector<int>({1,3,4,5}));
	int num=0;
	pair<int,int> res = overlap_rectangle(rects, num);
	cout<<num<<": "<<res.first<<' '<<res.second<<endl;
	return 0;
}


