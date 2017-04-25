class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        vector<int> record(n,0);
        record[0] = nums[0];
        int local_max = nums[0], res = nums[0];
        
        for (int i=1; i<n; i++){
            local_max = max(local_max+nums[i], nums[i]);
            record[i] = max(local_max, record[i-1]);
            if (record[i]>res) res = record[i];
        }
        return res;
    }
};
