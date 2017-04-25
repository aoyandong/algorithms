class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1+len2!=len3) return false;
        
        vector<vector<bool> > dp(len1+1, vector<bool>(len2+1,false));
        dp[0][0] = true;
        for (int i=0; i<len1; i++){
            if (s1[i]!=s3[i]) break;
            dp[i+1][0] = true;
        }
        for (int i=0; i<len2; i++){
            if (s2[i]!=s3[i]) break;
            dp[0][i+1] = true;
        }
        for (int i=1; i<=len1; i++){
            for (int j=1; j<=len2; j++){
                dp[i][j] = (dp[i-1][j]&&s1[i-1]==s3[i+j-1]) || (dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
            }
        }
        return dp[len1][len2];
    }
};
