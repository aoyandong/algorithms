class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int m = T.length();
        int n = S.length();
//        vector<vector<int> > dp(m+1, vector<int>(n+1,0));
        if (m==0) return 1;
        vector<int> pre(n+1,1);
        vector<int> cur(n+1,0);
//        for (int i=0; i<=n; i++) dp[0][i] = 1;
        
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                if (T[i-1]==S[j-1]){
//                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                    cur[j] = cur[j-1] + pre[j-1];
                }
                else{
//                    dp[i][j] = dp[i][j-1];
                    cur[j] = cur[j-1];
                }
                pre[j-1] = cur[j-1];
            }
            pre[n] = cur[n];
        }
//        return dp[m][n];
        return cur[n];
    }
};
