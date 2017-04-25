class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int cur_loc=A.size()-1;
        if (cur_loc<=0) return true;
        for (int i=A.size()-2; i>=0; i--){
            if ((A[i]+i)>=cur_loc){
                cur_loc = i;
            }
        }
        if (cur_loc==0) return true;
        else return false;
    }
};
