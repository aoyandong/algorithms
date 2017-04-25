class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        vector<int> A_count(26,0);
        vector<int> B_count(26,0);
    
        for (int i=0; i<A.length(); i++){
            A_count[A[i]-'A']++;
        }
        for (int i=0; i<B.length(); i++){
            B_count[B[i]-'A']++;
        }
    
        bool flag = true;
        for (int i=0; i<26; i++){
            if (A_count[i] < B_count[i]){
            	flag = false;
            	break;
            }
        }
        return flag;
    }
};