class Solution {
public:
    int countDigitOne(int n) {
        if (n<=0) return 0;
        long base=10;
        int count=0;
        while (true){
            count += (base/10)*(n/base);
            if ((n%base)/(base/10)==1) count+=1+(n%base)%(base/10);
            else if ((n%base)/(base/10)>1) count+=base/10;
            
            if (n/base==0) break;
            base = base*10;
        }
        return count;
    }
};
