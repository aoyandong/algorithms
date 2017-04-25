class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> > result;
        vector<int> tmp;
        if (k==1) {
            for (int i=1; i<=n; i++){
                result.push_back(vector<int>(1,i));
            }
            return result;
        }
        vector<vector<int> > result2;
        for (int i=n; i>0; i--){
            result2 = combine(i-1, k-1);
            for (int j=result2.size()-1; j>=0; j--){
                tmp = result2[j];
                tmp.push_back(i);
                result.push_back(tmp);
            }
        }
        return result;
    }
};