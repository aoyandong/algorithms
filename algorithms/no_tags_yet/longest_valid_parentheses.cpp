class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> S;
        int n = s.length();
        for (int i=0; i<n; i++){
            if (s[i]=='(') S.push(i);
            else{
                if (S.empty() || s[S.top()]==')') S.push(i);
                else if (s[S.top()]=='(') S.pop();
            }
        }
        
        int max_len=0;
        int start = n-1;
        while (!S.empty()){
            int tmp = S.top();
            S.pop();
            max_len = max(max_len, start-tmp);
            start = tmp-1;
        }
        max_len = max(max_len, start+1);
        return max_len;
    }
};
