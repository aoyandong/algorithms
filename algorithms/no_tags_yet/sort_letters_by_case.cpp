class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int n = letters.length();
        if (n<=1) return;
        
        int l=0, r=n-1;
        while (l<=r){
            if (letters[l]<='Z' && letters[r]>='a'){
                swap(letters[l++],letters[r--]);
                continue;
            }
            if (letters[l]>='a') l++;
            if (letters[r]<='Z') r--;
        }
    }
};

