class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        if (n<=0) return false;
        int m = n-1;
        if ((m&n)==0) return true;
        else return false;
    }
};