class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
        if (num.size()==0) return "0";
        vector<string> strs;
        for (int i=0; i<num.size(); i++){
            strs.push_back(to_string(num[i]));
        }
        sort(strs.begin(),strs.end(),[](string a, string b){return a+b>b+a;});
        string result;
        for (int i=0; i<strs.size(); i++){
            result+=strs[i];
        }
        while (result[0]=='0' && result.length()>1){
            result.erase(0,1);
        }
        return result;
    }
};