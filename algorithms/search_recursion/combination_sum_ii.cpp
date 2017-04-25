class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int> > result;
        if (num.size()==0) return result;
        sort(num.begin(),num.end());
        vector<int> cur;
        combinationSum_helper(num, target, result, cur, 0);
        return result;
    }

private:
    void combinationSum_helper(vector<int> &num, int target, vector<vector<int> > &result, vector<int> &cur, int start){
        if (target==0){
            result.push_back(cur);
            return;
        }
        for (int i=start; i<num.size() && target>=num[i]; i++){
            if (i!=start && num[i]==num[i-1]) continue;
            cur.push_back(num[i]);
            combinationSum_helper(num, target-num[i], result, cur, i+1);
            cur.pop_back();
        }
    }
};