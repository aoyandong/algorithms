class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        vector<int> record(n,0);
        int local_min = nums[0], res = nums[0];
        record[0] = nums[0];
        
        for (int i=1; i<nums.size(); i++){
            local_min = min(local_min+nums[i], nums[i]);
            record[i] = min(local_min, record[i-1]);
            if (record[i]<res) res = record[i];
        }
        return res;
    }
};

