class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int,int> map;
        vector<int> tmp;
        for (int i=0; i<nums.size(); i++){
            if (map.find(nums[i])!=map.end()){
                map[nums[i]]++;
            }
            else if (map.size()<k-1){
                map[nums[i]] = 1;
            }
            else{
                for (auto m:map){
                    m.second--;
                    if (m.second==0) tmp.push_back(m.first); //cannot remove here.
                }
                for (int i=0; i<tmp.size(); i++) map.erase(tmp[i]);
                tmp.clear();
            }
        }
        
        for (auto m:map) m.second=0;
        for (int i=0; i<nums.size(); i++){
            if (map.find(nums[i])!=map.end()){
                map[nums[i]]++;
            }
        }
        int maj_num=0, maj_count=0;
        for (auto m:map){
            if (maj_count<m.second){
                maj_num = m.first;
                maj_count = m.second;
            }
        }
        return maj_num;
    }
};

