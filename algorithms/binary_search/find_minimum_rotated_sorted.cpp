class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
    	int front=0, end=nums.size()-1, mid;
    	if (nums[front]<=nums[end]) return nums[front];
    	while ((front+1)!=end){
    		mid = front + (end-front)/2;
    		if (nums[mid]>nums[front]) front = mid;
    		if (nums[mid]<=nums[end]) end = mid;
    	}
        return nums[end];
    }
};