class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string> > res;
        helper(s,0,cur,res);
        return res;
    }

private:
    void helper(string &s, int start, vector<string> &cur, vector<vector<string> >&res){
        if (start==s.length()){
            res.push_back(cur);
            return;
        }
        for (int i=start; i<s.length(); i++){
            string tmp = s.substr(start,i-start+1);
            if (isPalindrome(tmp)){
                cur.push_back(tmp);
                helper(s,i+1,cur,res);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s){
        int i=0, j=s.length()-1;
        while(i<=j){
            if (s[i++]!=s[j--]) return false;
        }
        return true;
    }
};
