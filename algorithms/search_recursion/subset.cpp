class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	sort(nums.begin(),nums.end());
    	vector<vector<int> > result;
    	vector<int> cur;
    	result.push_back(cur);
    	for (int i=0; i<nums.size(); i++){
    		int n = result.size();
    		for (int j=0; j<n; j++){
    			cur = result[j];
    			cur.push_back(nums[i]);
    			result.push_back(cur);
    		}
    	}
    	return result;
    }
};