class Solution {
public:
    string originalDigits(string s) {
        vector<int> char_counts(26,0);
        vector<string> eng_words({"zero","two","four","six","eight","one","three","five","seven","nine"});
        vector<int> key_chars({'z','w','u','x','g','o','t','f','s','e'});
        vector<int> digit_map({0,2,4,6,8,1,3,5,7,9});
        vector<int> digit_counts(10,0);
        
        for (int i=0; i<s.length(); i++) char_counts[s[i]-'a']++;
        
        for (int i=0; i<10; i++){
            int key = key_chars[i]-'a';
            while (char_counts[key]>0){
                for (int j=0; j<eng_words[i].length(); j++) char_counts[eng_words[i][j]-'a']--;
                digit_counts[digit_map[i]]++;
            }
        }
        string res;
        for (int i=0; i<10; i++){
            if (digit_counts[i]>0) res+=string(digit_counts[i],i+'0');
        }
        return res;
    }
};
