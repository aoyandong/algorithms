class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        int n = s.length();
        vector<bool> indicator(n+1,false);
        indicator[0] = true;
        int last_true = 0;
        for (int i=0; i<n; i++){
            for (int j=last_true; j>=0; j--){
                if (indicator[j]){
                    if (dict.find(s.substr(j,i-j+1))!=dict.end()){
                        indicator[i+1] = true;
                        last_true = i+1;
                        break;
                    }
                }
            }
        }
        return indicator[n];
    }
};