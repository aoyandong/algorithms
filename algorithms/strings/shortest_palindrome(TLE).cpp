//For KK: simple idea, but without KMP, it is just too slow for worst case.
class Solution {
public:
    string shortestPalindrome(string s) {
        int i=0, j=s.length()-1, right=j;
        while (i<=j){
            if (s[j]!=s[i]){
                i=0;
                right--;
                j = right;
            }
            else{
                i++;
                j--;
            }
        }
        string res = s.substr(right+1,s.length()-right+1);
        reverse(res.begin(),res.end());
        res = res+s;
        return res;
    }
};
