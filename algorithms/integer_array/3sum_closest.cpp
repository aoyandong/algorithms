class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int j,k,sum;
        
        int result = nums[0] + nums[1] + nums[n-1];
        for (int i=0; i<n-2; i++){
            j = i+1;
            k = n-1;
            while (j<k){
                sum = nums[i]+nums[j]+nums[k];
                if (sum>target) k--;
                if (sum<target) j++;
                if (abs(sum-target) < abs(result-target)) result = sum;
                if (result==target) return target;
            }
        }
        return result;
    }
};
