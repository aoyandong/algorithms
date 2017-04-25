class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        if (nums.size()<4) return res;
        
        int n = nums.size();
        for (int i=0; i<n-3; i++){
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if (nums[i]+nums[n-1]+nums[n-2]+nums[n-3]<target) continue;
            for (int j=i+1; j<n-2; j++){
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if (nums[i]+nums[j]+nums[n-1]+nums[n-2]<target) continue;
                int k = j+1;
                int l = n-1;
                while (k<l){
                    if (nums[i]+nums[j]+nums[k]+nums[l] > target) l--;
                    else if (nums[i]+nums[j]+nums[k]+nums[l] < target) k++;
                    else{
                        res.push_back(vector<int>{nums[i],nums[j],nums[k],nums[l]});
                        while (k<l && nums[k]==res.back()[2]) k++;
                        while (k<l && nums[l]==res.back()[3]) l--;
                    }
                }
                while ((j<n-2) &&nums[j]==nums[j+1]) j++;
            }
            while ((i<n-3) && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};
