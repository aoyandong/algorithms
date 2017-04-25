class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        bool dot=false;
        int integer=0;
        double decimal=0, counter=10.0;
        for (unsigned i=0; i<n.length(); i++){
        	if (n[i]=='.'){
        		dot = true;
        		continue;
        	}
            if (!dot){
                integer = integer*10 + (n[i]-'0');
            }
            else{
                decimal += (n[i]-'0')/counter;
                counter *=10;
            }
        }
        string result;
        if (integer==0) result.push_back('0');
        char c;
        while (integer>0){
        	c = (integer%2)+'0';
        	result.insert(result.begin(),c);
        	integer = integer/2;
        }
        int num=0;
        if (decimal!=0){
        	result.push_back('.');
        	while (num<=32){
        		decimal = decimal*2;
        		if (decimal>=1 || fabs(decimal-1)<1.0e-10){ //Behavior of float is pretty wired on lintcode.
        			result.push_back('1');
        			decimal = decimal-1;
        		}
        		else{
        			result.push_back('0');
        			decimal = decimal;
        		}
        		num++;
        		if (fabs(decimal)<1.0e-10) break;
        	}
        }
        if (num>32) result="ERROR";
        return result;
    }
};
