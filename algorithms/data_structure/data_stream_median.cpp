struct compare{
    bool operator()(const int& l, const int& r){  
        return l > r;  
    }  
};
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> res;
        if (nums.size()==0) return res;
        
        priority_queue<int, vector<int>, compare> large; //min heap
        priority_queue<int> small; //max heap
        for (int i=0; i<nums.size(); i++){
            add_stream(large,small,nums[i]);
            res.push_back(small.top());
        }
        return res;
    }
    
    void add_stream(priority_queue<int, vector<int>, compare> &large, priority_queue<int> &small, int num){
        if (small.empty()){
            small.push(num);
            return;
        }
        int med = small.top();
        if (large.size()<small.size()){
            if (num<med){
                large.push(med);
                small.pop();
                small.push(num);
            }
            else large.push(num);
        }
        else{
            if (num>med){
                large.push(num);
                med = large.top();
                large.pop();
                small.push(med);
            }
            else small.push(num);
        }
    }
};

