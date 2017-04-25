class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
     
     //For KK: (you might practice other dp problem first, this one is kind of hard).
     //1. dp[i][j][l] from first j elements choose l items, sum to be i
     //2. initialization. dp[0][j][0]=1, from j choose l to make sum 0, only way is to choose nothing.
     //3. transition:
     //   dp[i][j][l] = dp[i][j-1][l] (Don't use jth element)
     //                +dp[i-A[j-1]][j-1][l-1] (Use jth element, but we have to make sure jth element can be used, i.e. it must be less than target)
     //4. return dp[target][n][k]
     
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        int n = A.size();
        if (n<1) return 0;
        
        vector<vector<vector<int> > > dp(target+1, vector<vector<int> >(n+1, vector<int>(k+1,0)));
        
        for (int j=0; j<=n; j++) dp[0][j][0] = 1;
        
        for (int i=1; i<=target; i++){
            for (int j=1; j<=n; j++){
                for (int l=1; l<=j && l<=k; l++){
                    dp[i][j][l] = dp[i][j-1][l];
                    if(i-A[j-1] >= 0){
                        dp[i][j][l] += dp[i-A[j-1]][j-1][l-1];
                    }
                }
            }
        }
        return dp[target][n][k];
    }
};
