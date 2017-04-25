class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        if (word.length()==0) return true;
        if (board.size()==0) return false;
        
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                if (helper(board,word,i,j)) return true;
            }
        }
        return false;
    }
    
    bool helper(vector<vector<char> > &board, string word, int i, int j){
        if (word.length()==0) return true;
        if (i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
        if (word[0]!=board[i][j]) return false;
        
        string sub_word(word.begin()+1, word.end());
        char tmp_c = board[i][j];
        board[i][j] = '$';
        bool flag = helper(board, sub_word, i-1, j) || helper(board, sub_word, i, j-1) || helper(board, sub_word, i+1, j) || helper(board, sub_word, i, j+1);
        board[i][j] = tmp_c;
        return flag;
    }
};
