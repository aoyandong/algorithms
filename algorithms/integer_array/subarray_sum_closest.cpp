class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        vector<int> sums;
        if (nums.size()<=1) return vector<int>(2,0);
        
        int cur = 0;
        sums.push_back(cur);
        for (int i=0; i<nums.size(); i++){
            cur += nums[i];
            sums.push_back(cur);
        }
        vector<int> sorted_sums(sums);
        sort(sorted_sums.begin(),sorted_sums.end());
        
        int min_diff = INT_MAX;
        int diff, sum1, sum2;
        for (int i=0; i<sorted_sums.size()-1; i++){
            diff = sorted_sums[i+1]-sorted_sums[i];
            if (diff<min_diff){
                sum1 = sorted_sums[i];
                sum2 = sorted_sums[i+1];
                min_diff = diff;
            }
        }
        int idx1, idx2;
        for (int i=0; i<sums.size(); i++){
            if (sums[i]==sum1){
                idx1 = i;
                break;
            }
        }
        for (int i=0; i<sums.size(); i++){
            if (sums[i]==sum2 && idx1!=i){
                idx2 = i;
                break;
            }
        }
        if (idx1>idx2) swap(idx1,idx2);
        vector<int> res;
        res.push_back(idx1);
        res.push_back(idx2-1);
        return res;
    }
};