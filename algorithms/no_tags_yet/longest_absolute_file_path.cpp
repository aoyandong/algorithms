class Solution {
public:
    int lengthLongestPath(string input) {
        int cur_level=-1, cur_max=0, cur_len=0;
        stack<int> S;
        
        for (int i=0; i<input.length(); i++){
            int level=0;
            while (input[i]=='\t'){ //Get the level of current line
                level++;
                i++;
            }
            int count = 0;
            bool is_file = false;
            while (input[i]!='\n'&&input[i]!='\0'){ //Get the count of the name
                count++;
                i++;
                if (input[i]=='.') is_file = true;
            }
            
            int diff = cur_level-level;
            for (int j=0; j<=diff; j++){ //Pop stack for lower levels
                cur_len = cur_len-S.top()-1;
                S.pop();
                cur_level--;
            }
            if (is_file){
                cur_max = max(cur_max, cur_len+count);
            }
            else{
                S.push(count);
                cur_len = cur_len+count+1;
                cur_level = level;
            }
            //cout<<cur_level<<'\t'<<cur_len<<endl;
        }
        return cur_max;
    }
};
