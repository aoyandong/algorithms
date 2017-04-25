class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    
    //O(n^2) solution (DP):
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int n=nums.size();
        if (n<=1) return n;
        
        vector<int> dp(n,1);
        int res = 1;
        for (int i=1; i<n; i++){
            for (int j=0; j<i; j++){
                if (nums[i]>nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }

    //O(nlogn) solution:
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int n=nums.size();
        if (n<=1) return n;
        
        vector<int> res;
        res.push_back(nums[0]);
        for (int i=1; i<n; i++){
            if (nums[i] > res[res.size()-1]) res.push_back(nums[i]);
            else{
                int lo=0, hi=res.size()-1,mid;
                while (lo<hi){
                    mid=lo+(hi-lo)/2;
                    if (res[mid]>nums[i]) hi=mid;
                    else lo=mid+1;
                }
                if (hi==0 || res[hi-1]!=nums[i]) res[hi] = nums[i];
            }
        }
        return res.size();
    }
};

