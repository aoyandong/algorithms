class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        if (n==0 && k==0) return 1;
        
        int res = 0;
        int base = 1;
        
        while (n/base>0){
            int cur = (n/base) %10;
            int high = n/base/10;
            int low = n - (n/base)*base;
            
            if (cur==k) res+=high*base+low+1;
            else if (cur>k) res+=(high+1)*base;
            else res+=high*base;
            
            if (k==0&&base!=1) res-=base; //correct leading 0 case
            base*=10;
        }
        return res;
    }
};