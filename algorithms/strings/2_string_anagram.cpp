class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        vector<int> s_count(256,0);
        vector<int> t_count(256,0);
    
        for (int i=0; i<s.length(); i++){
            s_count[s[i]]++;
        }
        for (int i=0; i<t.length(); i++){
            t_count[t[i]]++;
        }
    
        bool flag = true;
        for (int i=0; i<256; i++){
            if (s_count[i] != t_count[i]){
            	flag = false;
            	break;
            }
        }
        return flag;
    }
};