class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
    	vector<vector<string> > result;
    	vector<string> NQ(n,string(n,'.'));
    	vector<bool> flag90(n,false);
    	vector<bool> flag45(2*n-1, false);
    	vector<bool> flag135(2*n-1, false);
    	solver(result,NQ,n,0, flag90, flag45, flag135);
    	return result;
    }
private:    
    void solver(vector<vector<string> >& res, vector<string> NQ, int n, int row, vector<bool>& flag90, vector<bool>& flag45, vector<bool>& flag135){
    	if (row==n){
    		res.push_back(NQ);
    		return;
    	}
    	for (int col=0; col<n; col++){
    		if (isValid(row,col,n,flag90,flag45,flag135)){
    			NQ[row][col] = 'Q';
    			flag90[col] = true;
    			flag45[col-row+n-1] = true;
    			flag135[col+row] = true;
    			solver(res, NQ, n, row+1, flag90, flag45, flag135);
    			flag90[col] = false;
    			flag45[col-row+n-1] = false;
    			flag135[col+row] = false;
    			NQ[row][col] = '.';
    		}
    	}
    }
    
    bool isValid(int row, int col, int n, vector<bool>& flag90, vector<bool>& flag45, vector<bool>& flag135){
        if (flag90[col] || flag45[col-row+n-1] || flag135[col+row]) return false;
        else return true;
    }
    
    bool isValid2(vector<string> &NQ, int row, int col, int n){
        // Naive way
    	for (int i=0; i<row; i++){
    		if (NQ[i][col]=='Q') return false;
    	}
    	for (int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
    		if (NQ[i][j]=='Q') return false;
    	}
    	for (int i=row-1, j=col+1; i>=0 && j<n; i--,j++){
    		if (NQ[i][j]=='Q') return false;
    	}
    	return true;
    }
};
