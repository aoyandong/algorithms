class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int> > result;
        sort(nums.begin(),nums.end());
        int target;
        int j,k,tmp;
        for (int i=0; i<nums.size()-2; i++){
            target = -nums[i];
            j = i+1;
            k = nums.size()-1;
            while(j<k){
                tmp = nums[j]+nums[k];
                if (tmp<target) j++;
                if (tmp>target) k--;
                if (tmp==target){
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[j]);
                    triplet.push_back(nums[k]);
                    result.push_back(triplet);
                    while (j<k && nums[j]==triplet[1]) j++;
                    while (j<k && nums[k]==triplet[2]) k--;
                }
            }
            while (i<nums.size()-2 && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};
