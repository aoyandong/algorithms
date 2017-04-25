class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int> > paths(m,vector<int>(n,0));
        
        for (int i=0; i<m; i++){
            if (obstacleGrid[i][0]) break;
            paths[i][0] = 1;
        }
        for (int i=0; i<n; i++){
            if (obstacleGrid[0][i]) break;
            paths[0][i] = 1;
        }
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if (!obstacleGrid[i][j])
                    paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        
        return paths[m-1][n-1];
    }
};