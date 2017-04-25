class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
    	unordered_map<int,int> mp;
    	unordered_map<int,int>::iterator it;
    	int sum=0;
    	vector<int> range;
    	mp[0] = 0;
    	for (unsigned i=0; i<nums.size();i++){
    		sum += nums[i];
    		it = mp.find(sum);
    		if (it == mp.end()){
    			mp[sum] = i+1;
    		}
    		else{
    			range.push_back(it->second);
    			range.push_back(i);
    			break;
    		}
    	}
    	return range;
    }
};