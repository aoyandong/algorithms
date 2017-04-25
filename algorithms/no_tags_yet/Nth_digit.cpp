class Solution {
public:
    int findNthDigit(int n) {
        int digit=1;
        long base=9, count=0;
        while (true){
            count = digit*base;
            if (count>=n) break;
            else n-=count;
            digit++;
            base*=10;
        }
        base/=9;
        int num = n/digit + base - 1;
        if (digit==1) return n;
        if (n%digit==0) return (num)%10;
        else {
            num++;
            base*=10;
            cout<<num<<'\t'<<digit<<'\t'<<base<<endl;
            for (int i=0; i<n%digit; i++){
                num-=base*(num/base);
                base/=10;
            }
            return num/base;
        }
    }
};
