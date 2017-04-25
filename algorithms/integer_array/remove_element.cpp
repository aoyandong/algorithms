class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int len = 0;
        for (unsigned i=0; i<A.size(); i++){
            if (A[i]==elem){
                continue;
            }
            else{
                A[len] = A[i];
                len++;
            }
        }
        return len;
    }
};