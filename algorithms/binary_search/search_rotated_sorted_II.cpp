class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        int lo=0, hi=A.size()-1;
        if (hi<0) return false;
        
        while (lo<hi){
            int mid = lo + (hi-lo)/2;
            if (A[mid]==target) return true;
            if (A[mid]>A[hi]) {
                if (A[mid]>target && A[lo]<=target) hi = mid;
                else lo = mid+1;
            }
            else if (A[mid]<A[hi]){
                if (A[mid]<target && A[hi]>=target) lo=mid+1;
                else hi = mid;
            }
            else hi--;
        }
        if (A[lo]==target) return true;
        else return false;
    }
};
