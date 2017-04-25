class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        int count=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]=='1'){
                    region_grow(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
private:
    void region_grow(vector<vector<char>>& grid, int i, int j){
        int m=grid.size();
        int n=grid[0].size();
        if (i<0 || j<0 || i==m || j==n || grid[i][j]=='0') return;
        grid[i][j] = '0';
        region_grow(grid,i+1,j);
        region_grow(grid,i-1,j);
        region_grow(grid,i,j+1);
        region_grow(grid,i,j-1);
    }
};
