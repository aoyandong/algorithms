class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
    	int lo=0, hi=A.size()-1, mid;
    	while((lo+1)<hi){
    		mid = lo + (hi-lo)/2;
    		if (A[mid]>A[mid+1]) hi = mid;
    		if (A[mid]<A[mid+1]) lo = mid;
    	}
    	return hi;
    }
};
