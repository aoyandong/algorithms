class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int> > result;
        vector<int> cur;
        if (nums.size()==0) {
            result.push_back(cur);
            return result;
        }
        sort(nums.begin(),nums.end());
        return helper(nums,nums.size()-1);
    }
private:
    vector<vector<int> > helper(vector<int>& nums, int end){
        vector<vector<int> > result;
        vector<vector<int> > sub_re;
        vector<int> cur;
        if (end==0){
            result.push_back(vector<int>(1,nums[end]));
            return result;
        }
        int prev = end;
        for (int i=end; i>=0; i--){
            if (i!=end && (nums[i]==prev || nums[end]==nums[i])) continue;
            prev = nums[i];
            swap(nums[end], nums[i]);
            sub_re = helper(nums,end-1);
            for (int j=0; j<sub_re.size(); j++){
                cur = sub_re[j];
                cur.push_back(nums[end]);
                result.push_back(cur);
            }
            swap(nums[end],nums[i]);
        }
        return result;
        
    }
};