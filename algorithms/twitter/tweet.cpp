#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "twitter.h"
using namespace std;

//Implementation of Tweet
Tweet::Tweet(int u, int t, string v, Tweet* q): userid(u), timestamp(t), text(v), next(q) {}
int Tweet::get_timestamp() { return timestamp; }
string Tweet::get_content() { return text; }
int Tweet::get_uid() { return userid; }
Tweet* Tweet::get_next() { return next; }
