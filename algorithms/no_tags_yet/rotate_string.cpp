class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        int n = str.length();
        if (n<=1) return;
        offset = offset%n;
        
        //Solution 1
        reverse(str.begin(),str.end()-offset);
        reverse(str.end()-offset,str.end());
        reverse(str.begin(),str.end());
        
/*        //Solution 2
        int cur = 0, cur_n = n;
        while (offset!=0){
            for (int i=0; i<offset; i++){
                swap(str[cur+i],str[n-offset+i]);
            }
            cur_n = cur_n-offset;
            cur = cur+offset;
            offset = offset%cur_n;
        }
*/
    }
};
