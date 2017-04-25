class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int lo=0, hi=A.size()-1, mid;
        if (hi<0) return -1;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if (A[mid]<A[hi]) hi = mid;
            else if (A[mid]>A[hi]) lo = mid+1;
        }
        
        int rot = lo;
        if (target>A[A.size()-1]){
            lo = 0;
            hi = rot-1;
        }
        else{
            lo = rot;
            hi = A.size()-1;
        }
        
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if (A[mid]<target) lo = mid + 1;
            else if (A[mid]>target) hi = mid;
            else return mid;
        }
        if (A[lo]==target) return lo;
        else return -1;
    }
};