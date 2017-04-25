class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long count=0;
        for (long long i=5; n/i>=1; i*=5){
            count += n/i;
        }
        return count;
    }
};
