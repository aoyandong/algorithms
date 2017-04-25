class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int lo=0, hi=num.size()-1;
        if (hi<0) return 0;
        
        while (lo<hi){
            int mid = lo + (hi-lo)/2;
            if (num[lo]<num[hi]) return num[lo];
            if (num[lo]==num[hi]) lo++; //for cases like 1,1,0,1
            
            if (num[mid]>=num[lo]) lo = mid+1;
            else hi = mid;
        }
        return num[lo];
    }
};
