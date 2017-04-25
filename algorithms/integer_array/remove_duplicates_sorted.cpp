class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.size()==0) return 0;
        
        int len=1;
        for (unsigned i=1; i<nums.size(); i++){
            if (nums[i]==nums[len-1]){
                continue;
            }
            else{
                nums[len] = nums[i];
                len++;
            }
        }
        return len;
    }
};