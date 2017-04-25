class Solution {
public:
    void reverseWords(string &s) {
        int i=0, j=0;
        int n=s.length();
        int num_words=0;
        
        while (true){
            while (i<n && s[i]==' ') i++;
            if (i==n) break;
            
            if (num_words!=0) s[j++] = ' ';
            int start = j;
            while (i<n && s[i]!=' '){
                s[j] = s[i];
                j++; 
                i++;
            }
            reverse_helper(s,start,j-1);
        }
        s.resize(j);
        reverse_helper(s,0,j-1);
    }

private:
    void reverse_helper(string &s, int start, int end){
        int i=start, j=end;
        while (i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};
