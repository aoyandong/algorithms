class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        // write your code here
    	sort(nums.begin(),nums.end());
    	vector<vector<int> > result;
    	vector<int> cur;
    	result.push_back(cur);
    	int start, n;
    	for (int i=0; i<nums.size(); i++){
    		start = n;
    		n = result.size();
    		if (i==0 || nums[i]!=nums[i-1]) start = 0;
    		for (int j=start; j<n; j++){
    			cur = result[j];
    			cur.push_back(nums[i]);
    			result.push_back(cur);
    		}
    	}
    
    	return result;
    }
};
