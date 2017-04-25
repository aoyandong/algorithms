#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "twitter.h"
using namespace std;

//Implementation of User
User::User(int id, string name){
	head = nullptr;
	userID = id;
	username = name;
	followee.insert(id);
}
User::User(){
	head = nullptr;
	userID = -1;
}
void User::follow(int id){
	followee.insert(id);
}
void User::unfollow(int id){
	if (id==userID) return;
	if (followee.find(id)==followee.end()) return;
	followee.erase(id);
}
Tweet* User::get_tweets(){
	return head;
}
vector<int> User::get_followees(){
	vector<int> res;
	for (auto i:followee) res.push_back(i);
	return res;
}
void User::post(string text, int timestamp){
	Tweet* cur = new Tweet(userID, timestamp, text, head);
	head = cur;
}

