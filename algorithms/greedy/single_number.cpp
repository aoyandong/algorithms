class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int re=0;
        for (int i=0; i<A.size(); i++){
            re = re^A[i];
        }
        return re;
    }
};
