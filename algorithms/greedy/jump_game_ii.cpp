class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        if (A.size()<2) return 0;
        int i=0, cur_max=0, next_max=0;
        int level=0;
        while (true){
            level++;
            while (i<=cur_max){
                if ((A[i]+i)>next_max) next_max = A[i]+i;
                i++;
            }
            if (cur_max==next_max) return 0;
            if (next_max>=A.size()-1) return level;
            else{
                cur_max = next_max;
            }
        }
        
    }
};