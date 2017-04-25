class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    //1. dp[i][j] The longest common subsequence for A[0..i-1] and B[0..j-1]
    //2. Initial state: dp[0][j] = 0, dp[i][0] = 0
    //3. Transition:
    //   dp[i][j] = max(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]+1(if A[i-1]=B[j-1]))
    //4. Return dp[n][m]
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int n=A.size();
        int m=B.size();
        if (m==0 || n==0) return 0;
        
        vector<vector<int> > dp(n+1, vector<int>(m+1,0));
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                int tmp = dp[i-1][j-1];
                if (A[i-1]==B[j-1]) tmp++;
                dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]),tmp);
            }
        }
        return dp[n][m];
    }
};
