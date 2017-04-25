class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        
        // For KK, idea: rule out one column or one row from upper right corner.
        int m = matrix.size();
        if (m==0) return 0;
        int n = matrix[0].size();
        
        int i=0, j=n-1;
        int counter = 0;
        while (i<m && j>=0){
            if (matrix[i][j]>target) j--;
            else if (matrix[i][j]<target) i++;
            else{
                counter++;
                if (i<m-1) i++;
                else j--;
            }
        }
        return counter;
    }
};
