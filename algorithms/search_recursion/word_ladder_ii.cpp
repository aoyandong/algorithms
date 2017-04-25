class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        unordered_set<string> set1;
        unordered_set<string> set2;
        unordered_map<string, vector<string> > map;
        vector<vector<string> > ladders;
        set1.insert(start);
        set2.insert(end);
        bool flag=false;
        while (!set1.empty() && !set2.empty()){
            if (set1.size()<=set2.size()){
                flag = ladder_helper(set1,set2,dict,map,false);
            }
            else{
                flag = ladder_helper(set2,set1,dict,map,true);
            }
            if (flag) break;
        }
        
        vector<string> ladder;
        ladder.push_back(start);
        get_ladders(start,end,map,ladder,ladders);
        
        return ladders;
    }

private:
    bool ladder_helper(unordered_set<string>& set1, unordered_set<string>& set2, unordered_set<string>& dict, unordered_map<string, vector<string> >& map, bool flip){
        string word, cur;
        unordered_set<string> set_t;
        for (string word : set1) dict.erase(word);
        for (string word : set2) dict.erase(word);
        bool flag = false;
        for (auto it=set1.begin(); it!=set1.end(); it++){
            word = *it;
            for (int i=0; i<word.length(); i++){
                cur = word;
                for (int j=0; j<26; j++){
                    word[i] = j+'a';
                    if (set2.find(word)!=set2.end()){
                        flag = true;
                        if (flip) map[word].push_back(cur);
                        else map[cur].push_back(word);
                    }
                    else if (!flag && dict.find(word)!=dict.end()){
                        set_t.insert(word);
                        if (flip) map[word].push_back(cur);
                        else map[cur].push_back(word);
                    }
                }
                word = cur;
            }
        }
        swap(set1, set_t);
        return flag;
    }
    
    void get_ladders(string start, string end, unordered_map<string, vector<string> >& map, vector<string>& ladder, vector<vector<string> >& ladders){
        if (start==end){
            ladders.push_back(ladder);
        }
        for (int i=0; i<map[start].size(); i++){
            ladder.push_back(map[start][i]);
            get_ladders(map[start][i],end,map,ladder,ladders);
            ladder.pop_back();
        }
    }
};