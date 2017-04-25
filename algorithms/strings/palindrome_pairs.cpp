class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> map;
        for (int i=0; i<words.size(); i++){
            string word = words[i];
            reverse(word.begin(),word.end());
            map[word] = i;
        }
        bool self_palindrome = false;
        if (map.find("")!=map.end()) self_palindrome = true;
        vector<vector<int> >res;
        for (int i=0; i<words.size(); i++){
            if (words[i]=="") continue;
            for (int j=0; j<words[i].length(); j++){
                string left = words[i].substr(0,j);
                string right = words[i].substr(j,words[i].length()-j);
                
                bool left_palindrome = isPalindrome(left);
                bool right_palindrome = isPalindrome(right);
                int pair_idx;
                if (map.find(right)!=map.end() && left_palindrome){
                    pair_idx = map[right];
                    if (pair_idx!=i) res.push_back(vector<int>({pair_idx,i}));
                    else if (self_palindrome) res.push_back(vector<int>({map[""],i}));
                }
                if (map.find(left)!=map.end() && right_palindrome) res.push_back(vector<int>({i,map[left]}));
            }
        }
        return res;
    }

private:
    bool isPalindrome(string &s){
        int i=0, j=s.length()-1;
        while(i<=j){
            if (s[i++]!=s[j--]) return false;
        }
        return true;
    }
};
