class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
/*    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        // 1-way BFS, much slower than 2-way BFS
        unordered_map<string,bool> map;
        queue<string> Q;
        int length=0;
        if (start==end) return 1;
        
        int len = start.length(), n;
        string cur,tmp;
        Q.push(start);
        map[start] = true;
        while (!Q.empty()){
            length++;
            n = Q.size();
            for (int k=0; k<n; k++){
                cur = Q.front();
                Q.pop();
                for (int i=0; i<len; i++){
                    tmp = cur;
                    for (int j=0; j<26; j++){
                        tmp[i] = 'a'+j;
                        if (tmp==end) return length+1;
                        if (dict.find(tmp)!=dict.end() && map.find(tmp)==map.end()){
                            Q.push(tmp);
                            map[tmp] = true;
                        }
                    }
                }
            }
        }
        return 0;
    }*/
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // 2-way BFS
        unordered_set<string> set1;
        unordered_set<string> set2;
        int level=2;
        if (start==end) return 1;
        bool flag;
        set1.insert(start);
        set2.insert(end);
        while (!set1.empty() && !set2.empty()){
            if (set1.size()<=set2.size()) flag=helper(set1,set2,dict);
            else flag=helper(set2,set1,dict);
            if (flag) return level;
            else level++;
        }
        return 0;
    }
private:
    bool helper(unordered_set<string> &set1, unordered_set<string> &set2, unordered_set<string> &dict){
        unordered_set<string> set_t;
        char tmp;
        for (auto i=set1.begin();i!=set1.end();i++){
            string cur = *i;
            for (int i=0; i<cur.length(); i++){
                tmp = cur[i];
                for (int j=0; j<26; j++){
                    cur[i] = 'a'+j;
                    if (set2.find(cur)!=set2.end()) return true;
                    if (dict.find(cur)!=dict.end()){
                            set_t.insert(cur);
                            dict.erase(cur);
                    }
                }
                cur[i] = tmp;
            }
        }
        swap(set1,set_t);
        return false;
    }
};