class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    //For KK: do the mirror problem "previous permutation" as well (my solution is in this folder).
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
    	if (nums.size()==1)  return nums;
    	int i,j;
    	for (i=nums.size()-2; i>=0; --i){
    		if (nums[i]<nums[i+1]){
    			break;
    		}
    	}
    	if (i==-1) vector_reverse(nums,0);
    	else{
    		for (j=nums.size()-1; j>=i; --j){
    			if (nums[j]>nums[i]) break;
    		}
    		swap(nums[i],nums[j]);
    		vector_reverse(nums,i+1);
    	}
    	return nums;
    }
    void vector_reverse(vector<int> &A, int k){
    	int lo=k, hi=A.size()-1;
    	while (lo<hi){
    		swap(A[lo],A[hi]);
    		lo++;
    		hi--;
    	}
    }
};
