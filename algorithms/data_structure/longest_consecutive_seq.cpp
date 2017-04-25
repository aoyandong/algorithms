class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        unordered_set<int> set;
        for (int i=0; i<num.size(); i++) set.insert(num[i]);
        
        int longest = 0;
        for (auto i:set){
            if (set.find(i-1)==set.end()){
                int m = i+1;
                while(set.find(m)!=set.end()){
                    m++;
                }
                longest = max(longest, m-i);
            }
        }
        return longest;
    }
};
