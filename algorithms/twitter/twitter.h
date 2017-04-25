#ifndef TWITTER_H_
#define TWITTER_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Tweet{
private:
	int userid;
	int timestamp;
	string text;
	Tweet* next;
public:
	Tweet(int u, int t, string v, Tweet* q);
	int get_timestamp();
	string get_content();
	int get_uid();
	Tweet* get_next();
};

class User{
private:
	int userID;
	unordered_set<int> followee;
	Tweet* head;
public:
	string username;
	User();
	User(int id, string name);
	Tweet* get_tweets();
	void follow(int id);
	void unfollow(int id);
	vector<int> get_followees();
	void post(string text, int timestamp);
};


class Twitter{
private:
	int times;
	int ID;
	unordered_map<string, int> names; //username->id
	unordered_map<int, User> users;

public:
	Twitter();
	void newUser(string username);
	void follow(string follower, string followee);
	void unfollow(string follower, string followee);
	void postTweet(string username, string text);
	vector<string> getNewsFeed(string username);

	void testfollow(string username);
	void testtweets(string username);
};

#endif /* TWITTER_H_ */
