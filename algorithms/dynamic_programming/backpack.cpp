class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        int n = A.size();
//        vector<vector<bool> > dp(n+1, vector<bool>(m+1,false));
        vector<bool> dp(m+1,false);
        
//        for (int i=0; i<=n; i++) dp[i][0] = true;
        dp[0] = true;
        
/*        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if ((j-A[i-1])>=0){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
*/
        for (int i=1; i<=n; i++){
            for (int j=m; j>=0; j--){
                if ((j-A[i-1])>=0){
                    dp[j] = dp[j] || dp[j-A[i-1]];
                }
                else dp[j] = dp[j];
            }
        }
        for (int i=m; i>=0; i--){
//            if (dp[n][i]) return i;
            if (dp[i]) return i;
        }
    }
};