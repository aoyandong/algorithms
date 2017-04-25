class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int front=0, end=array.size();
    	int mid;
    	while ((front+1)<=end){
    		mid = front + (end-front)/2;
    		if (array[mid]<target) front = mid+1;
    		if (array[mid]>=target) end = mid;
    	}
    	if (array[front]==target) return front;
    	else return -1;
    }
};