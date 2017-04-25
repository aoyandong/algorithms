class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
    	if (strs.size()==0) return "";
    
    	int min_len = strs[0].length();
    	for (unsigned i=1; i<strs.size(); i++){
    		if (strs[i].length() < min_len){
    			min_len = strs[i].length();
    		}
    	}
    
    	string result("");
    	bool flag;
    	char tmp_c;
    	for (unsigned i=0; i<min_len; i++){
    		flag = true;
    		tmp_c = strs[0][i];
    		for (unsigned j=1; j<strs.size(); j++){
    			if (strs[j][i]!=tmp_c){
    				flag = false;
    				break;
    			}
    		}
    		if (flag){
    			result.push_back(tmp_c);
    		}
    	}
    	return result;
    }
};