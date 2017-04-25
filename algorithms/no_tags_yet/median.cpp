class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        priority_queue<int> pq;
        int k=ceil(nums.size()/2.0);
        for (int i=0; i<nums.size(); i++){
            if (pq.size()<k){
                pq.push(nums[i]);
                continue;
            }
            if (pq.top()>nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
