class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        if (num==0) return false;
        // Write your code here
        for (int i=2; i<6; i++){
            while (num%i==0) num/=i;
        }
        return num==1;
    }
};
