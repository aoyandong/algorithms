class Solution {
public:
//For KK, the hashmap can be replaced by a vector<int> of size 256.
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int max_len=0, cur=0;
        for (int i=0; i<s.length(); i++){
            if (map.find(s[i])==map.end()) map[s[i]]=i;
            else{
                cur = max(cur,map[s[i]]+1);
                map[s[i]] = i;
            }
            max_len = max(max_len, i-cur+1);
        }
        return max_len;
    }
};
