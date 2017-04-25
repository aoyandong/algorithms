class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int hi_base=1, lo_base=10;
        while (x/hi_base>=10) hi_base*=10;
        int tmp = x;
        while (hi_base>=lo_base){
            if ((tmp/hi_base)!=((tmp%lo_base)*10/lo_base)) return false;
            else{
                tmp-=tmp/hi_base*hi_base;
                tmp-=tmp%lo_base;
                hi_base/=10;
                lo_base*=10;
            }
        }
        return true;
    }
};
