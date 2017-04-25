class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        rev = s + '#' + rev;
        
        vector<int> lps(rev.length(),0);
        int len=0, i=1;
        while (i<rev.length()){
            if (rev[len]==rev[i]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if (len==0) {lps[i]=0; i++;}
                else len = lps[len-1];
            }
        }
        
        int cut = lps[rev.length()-1];
        string res = s.substr(cut,s.length()-cut);
        reverse(res.begin(),res.end());
        return res+s;
    }
};
