class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0=0, p1=0, p2=nums.size()-1;
        
        while (p1<=p2){
            while (nums[p1]==2 && p1<p2) {swap(nums[p1],nums[p2]); p2--;}
            while (nums[p1]==0 && p0<p1) {swap(nums[p1],nums[p0]); p0++;}
            p1++;
        }
    }
};
