class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        vector<int> res(1,1);
        int i=0, j=0, k=0;
        int counter = 1;
        while (counter<n){
            res.push_back(min(res[i]*2, min(res[j]*3, res[k]*5)));
            if (res.back()==res[i]*2) i++;
            if (res.back()==res[j]*3) j++;
            if (res.back()==res[k]*5) k++;
            counter++;
        }
        return res.back();
    }
};
