class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double> > dicesSum(int n) {
        // Write your code here
        // For KK:
        // 1. dp[i][j]: i dices rolls a sum of j
        // 2. initial state: dp[0][j] = 0; dp[1][1..6] = 1/6
        // 3. transition:
        //    dp[i][j] = sum_t (dp[i-1][t]*1/6) where j-6<=t<=j-1
        // 4. return dp[n][j] where j>=n
        
        vector<vector<double> > dp(n+1, vector<double>(6*n+1,0));
        for (int i=1; i<=6; i++) dp[1][i] = 1.0/6;
        for (int i=2; i<=n; i++){
            for (int j=i; j<=i*6; j++){
                for (int jt=1; jt<=6; jt++){
                    if (j-jt>0){
                        dp[i][j] += dp[i-1][j-jt]*1.0/6;
                    }
                }
            }
        }
        vector<pair<int, double> > res;
        for (int j=n; j<=6*n; j++){
            res.push_back(pair<int, double>(j, dp[n][j]));
        }
        return res;
    }
};
