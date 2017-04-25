class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
    	int x = a^b;
    	int result=0;
    	for (int i=0; i<32; i++){
    		if ((x&1) > 0) result++;
    		x = x>>1;
    	}
    	return result;
    }
};