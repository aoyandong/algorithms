class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int n = matrix.size();
        if (n==0) return false;
        int m = matrix[0].size();
        int row, col;
        for (row=0; row<n; row++){
            if (matrix[row][m-1] >= target){
                break;
            }
        }
        if (row==n) return false;
        for (col=0; col<m; col++){
            if (matrix[row][col]==target){
                return true;
            }
        }
        return false;
    }
};