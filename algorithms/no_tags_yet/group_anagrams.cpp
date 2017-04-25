class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > map;
        vector<vector<string> >res;
        
        for (int i=0; i<strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            map[tmp].push_back(strs[i]);
        }
        
        for (auto m:map){
            res.push_back(m.second);
        }
        return res;
    }
};
