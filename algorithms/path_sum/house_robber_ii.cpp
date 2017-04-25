class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        
        int step1=0, step2=0, step3=0;
        for (int i=1; i<n; i++){
            step3 = max(step2, step1+nums[i]);
            step1 = step2;
            step2 = step3;
        }
        int max_rob = step3;
        
        step1 = 0;
        step2 = 0;
        step3 = 0;
        for (int i=0; i<n-1; i++){
            step3 = max(step2, step1+nums[i]);
            step1 = step2;
            step2 = step3;
        }
        max_rob = max(max_rob,step3);
        return max_rob;
    }
};
