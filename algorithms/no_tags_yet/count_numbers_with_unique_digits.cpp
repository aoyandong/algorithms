class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        if (n>10) n = 10;
        int sum=1;
        for (int i=0; i<n; i++){
            sum += 9*permutation(9,i);
        }
        return sum;
    }
private:
    int permutation(int n, int k){
        if (k==0) return 1;
        int res=1;
        for (int i=0; i<k; i++) res *= (n-i);
        return res;
    }
};
