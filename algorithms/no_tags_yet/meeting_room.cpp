/*
 * meeting_room.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: day
 */

#include "everything.h"
using namespace std;

struct room{
	int id;
	pair<int,int> t;
	room(int _id, pair<int,int> _t): id(_id), t(_t){}
};

struct pq_comp{
    bool operator()(room& a, room& b){
        return a.t.second>b.t.second;
    }
};

static bool comp(pair<int,int>& a, pair<int,int>& b){
    return a.first<b.first;
}

int meeting_room(vector<pair<int,int>>& intervals, vector<vector<pair<int,int>>>& booking){
    int n = intervals.size();
    if (n==0) return 0;
    sort(intervals.begin(),intervals.end(),comp);
    priority_queue<room, vector<room>, pq_comp> pq;
    unordered_set<int> free_room;
    int room_id=0, id;
    int res = 0;
    for (int i=0; i<n; i++){
        while (!pq.empty() && pq.top().t.second<=intervals[i].first){
        	room cur = pq.top();
        	free_room.insert(cur.id);
        	pq.pop();
        }
        if (free_room.size()==0) {
        	vector<pair<int,int>> tmp(1, intervals[i]);
        	booking.push_back(tmp);
        	id = room_id++;
        }
        else {
        	id = *free_room.begin();
        	booking[id].push_back(intervals[i]);
        	free_room.erase(id);
        }
        pq.push(room(id,intervals[i]));
        res = max(res, int(pq.size()));
    }
    return res;
}
/*
int main(){
	vector<pair<int,int>> intervals;
	srand(time(NULL));
	for (int i=0; i<20; i++){
		int a = rand()%20;
		int b = rand()%20;
		if (a==b) i--;
		else if (a<b) intervals.push_back(make_pair(a,b));
		else intervals.push_back(make_pair(b,a));
	}
	for (auto i:intervals) cout<<i.first<<','<<i.second<<'\t';
	cout<<endl;
	vector<vector<pair<int,int>>> book;
	cout<<meeting_room(intervals, book)<<endl;
	for (auto v:book){
		for (auto u:v){
			cout<<u.first<<','<<u.second<<'\t';
		}
		cout<<endl;
	}
	return 0;
}
*/
