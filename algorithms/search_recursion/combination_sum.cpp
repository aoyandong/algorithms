class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > result;
        vector<int> cur;
        combinationSum_helper(candidates, target, result, cur, 0);
        return result;
    }

private:
    void combinationSum_helper(vector<int> &candidates, int target, vector<vector<int> > &result, vector<int> &cur, int start){
        if (target==0){
            result.push_back(cur);
            return;
        }
        for (int i=start; i<candidates.size() && target>=candidates[i]; i++){
            if (i>0 && candidates[i]==candidates[i-1]) continue;
            cur.push_back(candidates[i]);
            combinationSum_helper(candidates, target-candidates[i], result, cur, i);
            cur.pop_back();
        }
    }
};