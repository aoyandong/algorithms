class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;
        while (i<j){
            while (isalnum(s[i])==0 && i<j) {i++;}
            while (isalnum(s[j])==0 && i<j) j--;
            
            if (shift_case(s[i])!=shift_case(s[j])) return false;
            else {i++; j--;}
        }
        return true;
    }
    
    char shift_case(char c){
        if (c>='A'&&c<='Z') c = c-'A'+'a';
        return c;
    }
};
