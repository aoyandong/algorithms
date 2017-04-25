struct compare{
    bool operator()(const int &a, const int &b){
        return a>b;
    }
};
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
/*    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
	// Solution 1. priority queue, O(nlogk) time, O(k) space.
        priority_queue<int, vector<int>, compare> pq;
        for (int i=0; i<nums.size(); i++){
            if (pq.size()<k){
                pq.push(nums[i]);
                continue;
            }
            if (pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
*/
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
	// Solution 2. quick sort, O(n) time, worst O(n^2), O(1) space.
        int left=0, right=nums.size()-1;
        while (true){
            int pos = part(nums,left,right);
            if (pos==k-1) return nums[pos];
            else if (pos<k-1) left = pos+1;
            else right = pos-1;
        }
    }

private:
    int part(vector<int> &nums, int left, int right){
	//we can randomly choose pivot, and swap left and pivot, which gives average O(n) time.
        int pivot_pos = rand()%(right-left+1) + left;
        swap(nums[left], nums[pivot_pos]);

        int pivot = nums[left]; 
        int l=left+1, r=right;
        while (l<=r){
            if (nums[l]<=pivot && nums[r]>=pivot){
                swap(nums[l++],nums[r--]);
            }
            else if (nums[l]>pivot) l++;
            else if (nums[r]<pivot) r--;
        }
        swap(nums[left],nums[r]);
        return r;
    }
};
