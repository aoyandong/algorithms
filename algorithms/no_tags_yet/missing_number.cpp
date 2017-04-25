class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int running_sum=0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            running_sum += nums[i];
        }
        return n*(n+1)/2 - running_sum;
    }
};
