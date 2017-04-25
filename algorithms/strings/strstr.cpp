class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
    	int s_len = 0;
    	int t_len = 0;
    	if (source==NULL) return -1;
    	while (source[s_len]!='\0'){
    	    s_len++;
    	}
    	if (target==NULL) return -1;
    	while (target[t_len]!='\0'){
    	    t_len++;
    	}
    	
    	int flag = -1;
    	int j;
    	for (int i=0; i<=s_len-t_len; i++){
    		for (j=0; j<t_len; j++){
    			if (source[i+j] != target[j]) break;
    		}
    		if (j==t_len){
    			flag = i;
    			break;
    		}
    	}
    	return flag;
    }
};