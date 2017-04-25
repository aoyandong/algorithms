class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int n = triangle.size();
        vector<int> min_paths(triangle[n-1]);
        
        for (int i=(n-2); i>=0; i--){
            for (int j=0; j<=i; j++){
                min_paths[j] = min(min_paths[j], min_paths[j+1]) + triangle[i][j];
            }
        }
        
        return min_paths[0];
    }
};
