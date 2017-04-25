class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        int p1, p2;
        unordered_map<char, int> map;
        for (int i=0; i<target.length(); i++) map[target[i]]++;

        int count = map.size();
        p2=0;
        int min_len=INT_MAX;
        string res;
        for (p1=0; p1<source.length(); p1++){
            if (map.find(source[p1])==map.end()) continue;
            
            while (count!=0 && p2<source.length()){
                if (map.find(source[p2])!=map.end()){
                    map[source[p2]]--;
                    if (map[source[p2]]==0){
                        count--;
                    }
                }
                p2++;
                if (count==0) break;
            }
            if (count==0){
                while (map.find(source[p1])==map.end()||map[source[p1]]<0){
                    if (map.find(source[p1])==map.end()) {p1++; continue;}
                    else if (map[source[p1]]<0) { map[source[p1]]++; p1++;}
                    else break;
                }
                if (p2-p1 < min_len){
                    min_len = p2-p1;
                    res = source.substr(p1,min_len);
                }
            }
            
            map[source[p1]]++;
            count++;
        }
        return res;
    }
};

