class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    // 1. dp[i][j]: maximum sum of (i-1) subarrays of first j numbers.
    // 2. initialization: d[0][j] = 0, d[i][0] = 0
    // 3. transition:
    //    dp[i][j] = max(dp[i-1][t] + maxsubarray_1(numbers[t..j-1])) where i-1<=t<=j-1.
    //    from t numbers choose i-1 subarrays, and find the maximum subarray of last j-t numbers.
    // 4. return dp[k][n].
    
    int maxSubArray(vector<int> nums, int k) {
        // write your code here
        int n = nums.size();
        if (n<k) return 0;
        
        vector<vector<int> > dp(k+1, vector<int>(n+1,0));
        for (int i=1; i<=k; i++){
            for (int j=i; j<=n; j++){
                //maxsubarry_1
                int pre_max, cur_max, local_max;
                pre_max = cur_max = local_max = nums[j-1];
                dp[i][j] = dp[i-1][j-1] + nums[j-1];
                for (int t=j-2; t>=i-1; t--){
                    local_max = max(local_max+nums[t],nums[t]);
                    cur_max = max(local_max, pre_max);
                    dp[i][j] = max(dp[i-1][t]+cur_max, dp[i][j]);
                    pre_max = cur_max;
                }
            }
        }
        
        return dp[k][n];
    }
};
