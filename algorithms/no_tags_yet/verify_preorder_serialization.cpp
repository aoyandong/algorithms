// Capacity Solution
class Solution {
public:
//Every time we add a node, the capacity +1
    bool isValidSerialization(string preorder) {
        int n=preorder.size();
        if (n==0 || preorder=="#") return true;
        
        int capacity=1;
        for (int i=0; i<n; i++){
            if (preorder[i]!=',' && preorder[i]!='#'){
                capacity++;
                while (preorder[i]!=','&& preorder[i]!='#'&&i<n) i++;
            }
            if (preorder[i]==',') continue;
            else capacity--;
            if (capacity==0 && i!=n-1) return false;
            if (capacity<0) return false;
        }
        return capacity==0;
    }
};

// Intuitive Stack solution
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n=preorder.size();
        if (n==0 || preorder=="#") return true;
        
        int count=0;
        stack<char> stk;
        for (int i=0; i<n; i++){
            if (preorder[i]!=',' && preorder[i]!='#'){
                stk.push('T');
                while (preorder[i]!=','&& preorder[i]!='#'&&i<n) i++;
            }
            
            if (preorder[i]==',') continue;
            else{
                if (stk.empty()) return false;
                else if (stk.top()!='#') stk.push('#');
                else{   
                    while (!stk.empty()&&stk.top()=='#'){
                        if (stk.size()<2) return false;
                        stk.pop();
                        stk.pop();
                    }
                    if (stk.empty() && i==n-1) return true;
                    else if (stk.empty() && i<n-1) return false;
                    else stk.push('#');
                }
            }
        }
        if (!stk.empty()) return false;
        else return true;
    }
};