class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    //1. DP[i][j] the cost of adjust A[i-1] to number j (range 0-100) to meet requirement.
    //2. Initial state: DP[0][j] = 0;
    //3. Transition: DP[i+1][j] = min(DP[i][k]+abs(A[i]-j)) where abs(j-k)<=target.
    //4. Return the minimum in row DP[n][:]
    
    //5. If challenged for space O(n), simply record only the last row of DP.
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        int n = A.size();
        if (n<=1) return 0;
        
        vector<vector<int> > dp(n+1, vector<int>(100,0));
        for (int j=0; j<=100; j++) dp[0][j] = 0;
        
        for (int i=1; i<=n; i++){
            for (int j=0; j<=100; j++){
                int min_val = INT_MAX;
                for (int k=max(j-target, 0); k<=min(j+target,100); k++){
                    int tmp = dp[i-1][k] + abs(A[i-1]-j);
                    if (tmp<min_val){
                        min_val = tmp;
                        dp[i][j] = tmp;
                    }
                }
            }
        }
        int res = INT_MAX;
        for (int i=0; i<=100; i++){
            if (dp[n][i]<res) res = dp[n][i];
        }
        return res;
    }
};
