class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
    	int m = A.length();
    	int n = B.length();
    
    	int LongSuff[m+1][n+1];
    	int result = 0;
    
    	for (int i=0; i<=m; i++){
    		for (int j=0; j<=n; j++){
    			if (i==0 || j==0){
    				LongSuff[i][j] = 0;
    				continue;
    			}
    			if (A[i-1]==B[j-1]){
    				LongSuff[i][j] = LongSuff[i-1][j-1]+1;
    				if (result < LongSuff[i][j]){
    					result = LongSuff[i][j];
    				}
    			}
    			else{
    				LongSuff[i][j]=0;
    			}
    		}
    	}
    	return result;
    }
};