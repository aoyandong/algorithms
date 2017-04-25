class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int dashes = 0;
        for (int i=0; i<S.length(); i++){
            if (S[i]=='-') dashes++;
        }
        if (S.length()==dashes) return "";
        
        int num_dash = (S.length()-dashes-1)/K;
        int counter = 0;
        string res(S.length()-dashes+num_dash,'#');
        int j=res.length()-1;
        for (int i=S.length()-1; i>=0; i--){
            if (S[i]!='-' && S[i]>='a' && S[i]<='z') {res[j] = S[i]-'a'+'A'; counter++;j--;}
            else if (S[i]!='-') {res[j] = S[i]; counter++;j--;}
            if (counter==K && j>=0){
                res[j] = '-';
                j--;
                counter = 0;
            }
        }
        return res;
    }
};
