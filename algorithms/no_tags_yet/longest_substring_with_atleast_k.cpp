class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n==0) return 0;
        
        vector<int> count(26,0);
        for (int i=0; i<n; i++){
            count[s[i]-'a']++;
        }
        int l, r;
        for (int i=0; i<n; i++){
            if (count[s[i]-'a'] <k && count[s[i]-'a']!=0){
                l = longestSubstring(s.substr(0,i),k);
                int j = i+1;
                while (j<n && count[s[j]-'a'] <k && count[s[j]-'a']!=0) j++;
                r = longestSubstring(s.substr(j,n-j),k);
                return max(l,r);
            }
        }
        return n;
    }
};
