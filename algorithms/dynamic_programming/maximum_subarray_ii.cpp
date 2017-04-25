class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int n = nums.size();
        vector<int> max_l(n,0), max_r(n,0);
        int max_lt, max_rt;
        max_lt = max_l[0] = nums[0];
        max_rt = max_r[n-1] = nums[n-1];
        
        for (int i=1; i<n-1; i++){
            max_lt = max(max_lt+nums[i], nums[i]);
            max_l[i] = max(max_l[i-1], max_lt);
            max_rt = max(max_rt+nums[n-i-1], nums[n-i-1]);
            max_r[n-i-1] = max(max_r[n-i], max_rt);
        }
        
        int res = INT_MIN;
        for (int i=0; i<n-1; i++){
            res = max(res, max_l[i]+max_r[i+1]);
        }
        return res;
    }
};

