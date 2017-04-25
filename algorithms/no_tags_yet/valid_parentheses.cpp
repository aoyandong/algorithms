class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        char cur;
        for (int i=0; i<s.length(); i++){
            if (s[i]=='(' || s[i]=='[' || s[i]=='{'){
                S.push(s[i]);
            }
            else if (s[i]==')' || s[i]==']' || s[i]=='}'){
                if (S.empty()) return false;
                cur = S.top();
                if (s[i]==')'&&cur!='(') return false;
                else if (s[i]==']'&&cur!='[') return false;
                else if (s[i]=='}'&&cur!='{') return false;
                S.pop();
            }
        }
        if (!S.empty()) return false;
        return true;
    }
};
