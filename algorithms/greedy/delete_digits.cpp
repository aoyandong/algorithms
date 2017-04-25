class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        int n = A.length();
        if (n==0 || n==k) return "0";
        string res(n-k,'0');
        for (int i=0,j=0; i<n; i++){
            while (i-j<k && j>0 && res[j-1]>A[i]) j--;
            if (j<n-k) res[j++] = A[i];
        }
        while (res.size()>1&&res[0]=='0') res.erase(0,1);
        
        return res;
    }
/*
    string DeleteDigits(string A, int k) {
        // wirte your code here
    	stack<int> digits;
    	int n = A.length();
    	if (n==k) return "";
    	int num = 0;
    	for (int i=0; i<n; i++){
    		while (!digits.empty() && digits.top()>A[i] && num<k){
    			digits.pop();
    			num++;
    		}
    		digits.push(A[i]);
    	}
    	while (num<k){
    		digits.pop();
    		num++;
    	}
    	string result(n-k,'0');
    	for (int i=n-k-1; i>=0; i--){
    		result[i] = digits.top();
    		digits.pop();
    	}
    	int count=0;
    	for (int i=0; i<result.length(); i++){
    		if (result[i]!='0') break;
    		else count++;
    	}
    	if (result.length()==count) result="0";
    	else result.erase(result.begin(),result.begin()+count);
    	return result;
    }
*/
};
