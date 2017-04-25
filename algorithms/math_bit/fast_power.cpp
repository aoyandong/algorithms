class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if (n==0) return 1%b;
        if (n==1) return a%b;
        
        long mod = fastPower(a,b,n/2);
        mod = (mod*mod)%b;
        
        if (n%2==1){
            mod = ((a%b)*mod)%b;
        }
        return mod;
    }
};