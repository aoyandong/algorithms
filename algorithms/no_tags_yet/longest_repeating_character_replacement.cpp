class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        vector<int> count(26,0);
        int max_len=0, begin=0, max_counts=0;
        
        for (int end=0; end<n; end++){
            count[s[end]-'A']++;
            if (max_counts<count[s[end]-'A']) max_counts = count[s[end]-'A'];
            while (end-begin+1 > k+max_counts){
                count[s[begin]-'A']--;
                begin++;
                for (int i=0; i<26; i++) max_counts = max(max_counts, count[i]);
            }
            max_len = max(max_len, end-begin+1);
        }
        return max_len;
    }
};
