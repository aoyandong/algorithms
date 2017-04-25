class Solution {
public:
    string simplifyPath(string path) {
        vector<string> path_parts;
        string words;
        for (int i=0; i<=path.length(); i++){
            if (i==path.length() || path[i]=='/'){ //handles last part which may not end with '/'
                if (words.length()==0) continue;
                if (words==".."){
                    if (path_parts.size()!=0) path_parts.pop_back();
                }
                else if (words!="."){
                    path_parts.push_back(words);
                }
                words.clear();
            }
            else words += path[i];
        }
        
        string res;
        if (path_parts.size()==0) return "/";
        for (int i=0; i<path_parts.size(); i++){
            res = res + '/' + path_parts[i];
        }
        return res;
    }
};
