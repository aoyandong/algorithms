class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> result(nums.size(),1);
        for (int i=1; i<nums.size(); i++){
            result[i] = result[i-1] * nums[i-1];
        }
        
        long long tmp=1;
        for (int i=nums.size()-2; i>=0; i--){
            tmp = tmp*nums[i+1];
            result[i] = result[i]*tmp;
        }

        return result;
    }
};