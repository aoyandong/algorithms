class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
    	int result=0;
    	vector<bool> flag90(n,false);
    	vector<bool> flag45(2*n-1, false);
    	vector<bool> flag135(2*n-1, false);
    	solver(result,n,0, flag90, flag45, flag135);
    	return result;
    }
private:    
    void solver(int& res, int n, int row, vector<bool>& flag90, vector<bool>& flag45, vector<bool>& flag135){
    	if (row==n){
    		res++;
    		return;
    	}
    	for (int col=0; col<n; col++){
    		if (isValid(row,col,n,flag90,flag45,flag135)){
    			flag90[col] = true;
    			flag45[col-row+n-1] = true;
    			flag135[col+row] = true;
    			solver(res, n, row+1, flag90, flag45, flag135);
    			flag90[col] = false;
    			flag45[col-row+n-1] = false;
    			flag135[col+row] = false;
    		}
    	}
    }
    
    bool isValid(int row, int col, int n, vector<bool>& flag90, vector<bool>& flag45, vector<bool>& flag135){
        if (flag90[col] || flag45[col-row+n-1] || flag135[col+row]) return false;
        else return true;
    }
};
