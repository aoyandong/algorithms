class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        vector<int> res(nums.begin(), nums.end());
        int i,j;
        for (i=nums.size()-2; i>=0; i--){
            if (nums[i+1]<nums[i]) break;
        }
        if (i<0){
            reverse(res.begin(), res.end());
            return res;
        }
        
        for (j=nums.size()-1; j>i; j--){
            if (nums[j]<nums[i]) break;
        }
        swap(res[i],res[j]);
        reverse(res.begin()+i+1, res.end());
        return res;
    }
};
