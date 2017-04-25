class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        int sign=1, num=0, i=0;
        while (str[i]==' ') {i++;}
        if (str[i]=='-' || str[i]=='+'){
            sign = 1 - 2*(str[i]=='-');
            i++;
        }
        
        while (i<str.length()){
            if (str[i]<'0' || str[i]>'9') break;
            if (num>INT_MAX/10 || (num==INT_MAX/10 && (str[i]-'0'>=INT_MAX%10))){
                if (sign==1) return INT_MAX;
                else return INT_MIN;
            }
            num = 10*num + str[i]-'0';
            i++;
        }
        
        return num*sign;
    }
};
