class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
    	vector<int> result(2,-1);
    	int lo=0, hi=A.size()-1, mid;
    	if (hi<0) return result;
    	while(lo<hi){
    		mid = lo + (hi-lo)/2;
    		if (A[mid]>=target) hi = mid;
    		else if (A[mid]<target) lo = mid+1;
    	}
    	if (A[lo]==target) result[0] = lo;
    	else{
    		return result;
    	}
    
    	hi = A.size()-1;
    	while(lo<hi){
    		mid = lo + (hi-lo)/2 + 1;
    		if (A[mid]>target) hi = mid-1;
    		else if (A[mid]<=target) lo = mid;
    	}
    	result[1] = hi;
    	return result;
    }
};