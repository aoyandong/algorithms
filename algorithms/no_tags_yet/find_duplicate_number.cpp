class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo=1, hi=nums.size();
        
        while (lo<hi){
            int count=0;
            int mid = lo + (hi-lo)/2;
            for (int i=0; i<nums.size(); i++){
                if (nums[i]<=mid) count++;
            }
            if (count<=mid) lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
};
