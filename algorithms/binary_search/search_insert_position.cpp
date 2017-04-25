class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int n = A.size();
    	int lo = 0;
    	int hi = n;
    	int mid;
    	while (lo<hi){
    		mid = (lo+hi)/2;
    		if (A[mid]>=target) hi=mid;
    		else lo = mid+1;
    	}
    	return lo;
    }
};