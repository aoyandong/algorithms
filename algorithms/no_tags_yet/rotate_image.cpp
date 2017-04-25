class Solution {
public:
    //For KK, there is a demo png in the folder (if you want to understand this faster).
    void rotate(vector<vector<int>>& matrix) {
        int i=0, j=matrix.size()-1;
        while (i<j){
            for (int t=0; t<(j-i); t++){
                swap(matrix[i][i+t], matrix[i+t][j]);
                swap(matrix[i][i+t], matrix[j][j-t]);
                swap(matrix[i][i+t], matrix[j-t][i]);
            }
            i++;
            j--;
        }
    }
};
