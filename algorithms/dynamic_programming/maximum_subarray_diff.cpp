class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int n = nums.size();
        vector<int> min_l(n,0), min_r(n,0), max_l(n,0), max_r(n,0);
        
        int min_lt, min_rt, max_lt, max_rt;
        min_l[0] = max_l[0] = min_lt = max_lt = nums[0];
        min_r[n-1] = max_r[n-1] = min_rt = max_rt = nums[n-1];
        
        for (int i=1; i<n; i++){
            min_lt = min(min_lt+nums[i], nums[i]);
            min_l[i] = min(min_l[i-1], min_lt);
            max_lt = max(max_lt+nums[i], nums[i]);
            max_l[i] = max(max_l[i-1], max_lt);
            
            min_rt = min(min_rt+nums[n-i-1], nums[n-i-1]);
            min_r[n-i-1] = min(min_r[n-i], min_rt);
            max_rt = max(max_rt+nums[n-i-1], nums[n-i-1]);
            max_r[n-i-1] = max(max_r[n-i], max_rt);
        }
        int res = INT_MIN;
        for (int i=0; i<n-1; i++){
            res = max(res, max(abs(max_l[i]-min_r[i+1]), abs(min_l[i]-max_r[i+1])));
        }
        return res;
    }
};

