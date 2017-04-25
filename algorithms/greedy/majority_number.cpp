class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int count=0, maj;
        for (int i=0; i<nums.size(); i++){
            if (count==0) maj = nums[i];
            if (nums[i]==maj) count++;
            else count--;
        }
        return maj;
    }
};
