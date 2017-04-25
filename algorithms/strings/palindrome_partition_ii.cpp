class Solution {
public:
    //For KK:
    // dp[i][j], wheather s[i..j] is palindrome, dp[i][i]=true;
    // cut[i], mincut from 0 to i
    
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool> > dp(n+1, vector<bool>(n+1,false));
        vector<int> cuts(n+1,0);
        
        for (int i=0; i<=n; i++) {
            cuts[i] = i-1;
            dp[i][i] = true;
        }
        for (int i=2; i<=n; i++){
            for (int j=i-1; j>=0; j--){
                if (s[i-1]==s[j]){
                    if (i-j<3 || dp[j+1][i-2]){
                        dp[j][i-1] = true;
                        cuts[i] = min(cuts[i], cuts[j]+1);
                    }
                }
            }
        }
        return cuts[n];     
    }
};
