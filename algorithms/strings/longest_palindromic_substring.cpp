class Solution {
public:
    string longestPalindrome(string s) {
        int left, right, max_len=0, n=s.length(), start;
        if (n==0) return 0;
        for (int i=0; i<n && n-i>=max_len/2; i++){
            left = right = i;
            while(right<n-1 && s[right+1]==s[right]) right++;
            while (left>0 && right<n-1 && s[left-1]==s[right+1]) { left--; right++; }
            if (right-left+1 > max_len){
                max_len=right-left+1;
                start = left;
            }
        }
        return s.substr(start,max_len);
    }
};
