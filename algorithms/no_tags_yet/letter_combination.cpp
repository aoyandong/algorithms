class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.length()==0) return res;
        
        res.push_back("");
        for (int i=0; i<digits.length(); i++){
            vector<string> running_res;
            string cur = charmap[digits[i]-'0'];
            for (int j=0; j<cur.length(); j++){
                for (int k=0; k<res.size(); k++){
                    running_res.push_back(res[k]+cur[j]);
                }
            }
            res = running_res;
        }
        return res;
    }
};