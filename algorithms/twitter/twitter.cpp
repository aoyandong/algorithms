#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "twitter.h"
using namespace std;

//Implementation of Twitter
Twitter::Twitter(): times(0), ID(0) {}

void Twitter::newUser(string username){
	if (names.find(username)!=names.end()){
		cout<<"username is already taken."<<endl;
		return;
	}
	names[username] = ID;
	users[ID] = User(ID, username);
	ID++;
}

void Twitter::follow(string follower, string followee){
	if (names.find(follower)==names.end() || names.find(followee)==names.end()) {
		cout<<"user not found"<<endl;
		return;
	}
	int followerID = names[follower];
	int followeeID = names[followee];
	users[followerID].follow(followeeID);
}

void Twitter::unfollow(string follower, string followee){
	if (names.find(follower)==names.end() || names.find(followee)==names.end()) {
		cout<<"user not found";
		return;
	}
	int followerID = names[follower];
	int followeeID = names[followee];
	users[followerID].unfollow(followeeID);
}

void Twitter::postTweet(string username, string text){
	int userid = names[username];
	users[userid].post(text, times);
	times++;
}

struct compare{
	bool operator()(Tweet* p, Tweet* q){
		return p->get_timestamp()<q->get_timestamp();
	}
};
vector<string> Twitter::getNewsFeed(string username){
	int userid = names[username];
	vector<int> followees = users[userid].get_followees();
	priority_queue<Tweet*, vector<Tweet*>, compare> pq;
	vector<string> res;
	for (auto f:followees){
		Tweet* head = users[f].get_tweets();
		if (head) pq.push(head);
	}
	while (!pq.empty() && res.size()<5){
		Tweet* cur = pq.top();
		pq.pop();
		string tmp = users[cur->get_uid()].username + "(" + to_string(cur->get_timestamp()) + ")" +
					": " + cur->get_content();
		res.push_back(tmp);
		if (cur->get_next()) pq.push(cur->get_next());
	}
	return res;
}

void Twitter::testfollow(string username){
	vector<int> tmp = users[names[username]].get_followees();
	for (auto i:tmp){
		cout<<users[i].username<<' ';
	}
	cout<<endl;
}

void Twitter::testtweets(string username){
	int userid = names[username];
	User cur = users[userid];
	Tweet* head = cur.get_tweets();
	while (head){
		cout<<head->get_timestamp()<<' ';
		cout<<head->get_content()<<endl;
		head = head->get_next();
	}
}






