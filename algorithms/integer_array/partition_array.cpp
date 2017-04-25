class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if (nums.size()==0) return 0;
        int i,j;
        i = 0;
        j = nums.size()-1;
        while(i<j){
            if (nums[i]>=k){
                swap(nums[i],nums[j]);
                j--;
            }
            else i++;
        }
        if (nums[i]>=k) return i;
        if (nums[i]<k) return i+1;
    }
};