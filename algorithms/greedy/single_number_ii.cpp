//For KK: the idea is here:
// https://discuss.leetcode.com/topic/22821/an-general-way-to-handle-all-this-sort-of-questions/2
// The best explanation is by user Blackknight.

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int a=0, b=0;
        int tmp;
        for (int i=0; i<A.size(); i++){
            tmp = (a&~b&(~A[i])) | (~a&b&(A[i]));
            b = (~a&b&(~A[i])) | (~a&~b&(A[i]));
            a = tmp;
        }
        return a|b;
    }
};
