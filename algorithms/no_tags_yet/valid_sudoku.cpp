class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char> >& board) {
        bool col[9][9]={false}, row[9][9]={false}, box[9][9]={false};
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j]!='.'){
                    int num = board[i][j]-'1';
                    int k = i/3*3 + j/3;
                    if (col[i][num] || row[j][num] || box[k][num]) return false;
                    col[i][num] = row[j][num] = box[k][num] = true;
                }
            }
        }
        return true;
    }
};
