class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.size()<=2) return nums.size();
        int cur=0, len=0, counter=0;
        for (int i=1; i<nums.size(); i++){
            if (nums[cur]!=nums[i]){
                if (counter!=0){ counter = 0; }
                swap(nums[++cur],nums[i]);
            }
            else if (nums[cur]==nums[i] && counter==0){
                counter++;
                swap(nums[++cur],nums[i]);
            }
            else{
                continue;
            }
        }
        return cur+1;
    }
};
