class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int n = nums.size();
        vector<int> record(n,1);
        vector<int> record_abs(n,1);
        
        record[0] = nums[0];
        record_abs[0] = abs(nums[0]);
        int max_prod = record[0];
        
        for (int i=1; i<n; i++){
            record_abs[i] = abs(nums[i])*record_
        }
    }
};