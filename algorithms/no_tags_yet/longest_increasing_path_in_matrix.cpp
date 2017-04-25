class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        int res=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                dfs(matrix,dp,i,j);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>&matrix, vector<vector<int>>&dp, int i, int j){
        if (dp[i][j]!=0) return;
        
        int left, right, up, down;
        if (j>0 && matrix[i][j] < matrix[i][j-1]) {dfs(matrix,dp,i,j-1); left=dp[i][j-1];}
        else left=0;
        if (i>0 && matrix[i][j] < matrix[i-1][j]) {dfs(matrix,dp,i-1,j); up=dp[i-1][j];}
        else up=0;
        if (j<matrix[0].size()-1 && matrix[i][j] < matrix[i][j+1]) {dfs(matrix,dp,i,j+1); right=dp[i][j+1];}
        else right=0;
        if (i<matrix.size()-1 && matrix[i][j] < matrix[i+1][j]) {dfs(matrix,dp,i+1,j); down=dp[i+1][j];}
        else down=0;
        
        dp[i][j] = 1 + max(max(max(left,right),up),down);
    }
};
