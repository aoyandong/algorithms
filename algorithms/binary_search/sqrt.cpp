class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if (x==0 || x==1) return x;

        int upper = x;
        int lower = 1;
        int num = lower + (upper-lower)/2;
        while ((lower+1)!=upper){
            if (num>x/num) upper = num;
            else lower = num;
            num = lower + (upper-lower)/2;
        }
        return lower;
    }
};