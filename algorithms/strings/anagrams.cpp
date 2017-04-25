class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
    	unordered_map<string,vector<string>> mp;
    	vector<string> anagrams;
    	string sorted_input;
    	for (unsigned i=0; i<strs.size(); i++){
    		sorted_input = sort_input(strs[i]);
    		mp[sorted_input].push_back(strs[i]);
    	}
    	for (auto m:mp){
    		if (m.second.size()>1){
    		    for (unsigned i=0; i<m.second.size(); i++){
    		        anagrams.push_back(m.second[i]);    
    		    }
    		}
    	}
        return anagrams;        
    }
    string sort_input(string input){
    	sort(input.begin(),input.end());
    	return input;
    }
};
