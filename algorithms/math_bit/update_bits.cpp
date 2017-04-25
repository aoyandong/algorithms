class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        int mask=0;
        for (int shift=31; shift>j; shift--) mask+=(1<<shift);
        for (int shift=i-1; shift>=0; shift--) mask+=(1<<shift);
        
        n = n&mask;
        n = n + (m<<i);
        return n;
    }
};