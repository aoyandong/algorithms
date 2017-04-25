class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
/*//using vector.
        int i,j,tmp,num1,num2;
        vector<int> result;
        vector<int> sorted_nums(nums.begin(),nums.end());
        sort(sorted_nums.begin(),sorted_nums.end());
        i = 0;
        j = nums.size()-1;
        while (i<j){
            tmp = sorted_nums[i]+sorted_nums[j];
            if (tmp==target){
                num1 = sorted_nums[i];
                num2 = sorted_nums[j];
                break;
            }
            else if (tmp<target) i++;
            else j--;
        }
        for (i=0; i<nums.size(); i++){
            if (nums[i] == num1 || nums[i] == num2) result.push_back(i+1);
        }
        return result;
*/
//hashmap        
        unordered_map<int,int> mymap;
        unordered_map<int,int>::iterator it;
        vector<int> result;
        for (int i=0; i<nums.size(); i++){
            it = mymap.find(target-nums[i]); 
            if (it != mymap.end()){
                result.push_back(it->second);
                result.push_back(i+1);
            }
            else{
                mymap[nums[i]] = i+1;
            }
        }
        return result;
    }
};