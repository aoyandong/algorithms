class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        vector<int> counts(52,0);
        for (int i=0; i<n; i++){
            if (s[i]<='Z') counts[s[i]-'A']++;
            else counts[s[i]-'a'+26]++;
        }
        
        int res=0, odd=0;
        for (int i=0; i<52; i++){
            res+=counts[i]/2*2;
            if (counts[i]%2==1) odd=1;
        }
        return res+odd;
    }
};
