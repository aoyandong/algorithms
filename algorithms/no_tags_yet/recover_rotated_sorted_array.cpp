class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int rot=nums.size();
        for (int i=0; i<nums.size()-1; i++){
            if (nums[i]>nums[i+1]){
                rot = i+1;
                break;
            }
        }
        reverse(nums.begin(),nums.begin()+rot);
        reverse(nums.begin()+rot, nums.end());
        reverse(nums.begin(),nums.end());
    }
};
