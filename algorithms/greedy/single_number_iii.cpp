class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int diff = 0;
        for (int i=0; i<A.size(); i++){
            diff ^= A[i];
        } 
        diff &= -diff; //find one bit that is 1, and separate numbers based on this bit.
        
        vector<int> result(2,0);
        for (int i=0; i<A.size(); i++){
            if (A[i]&diff) result[0]^=A[i];
            else result[1]^=A[i];
        }
        return result;
    }
};
