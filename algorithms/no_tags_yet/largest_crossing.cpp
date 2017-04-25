/*
 * largest_crossing.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: day
 */
#include "everything.h"
using namespace std;

int largest_crossing(vector<string>& matrix){
	int m = matrix.size();
	int n = matrix[0].length();
	vector<vector<int>> memo(m,vector<int>(n,0));
	for (int i=0; i<m; i++){
		for (int j=0, len=0; j<n; j++){
			if (matrix[i][j]=='1') len++;
			else len=0;
			memo[i][j] = len;
		}
		for (int j=n-1, len=0; j>=0; j--){
			if (matrix[i][j]=='1') len++;
			else len=0;
			memo[i][j] = min(memo[i][j],len);
		}
	}
	int res=0;
	for (int j=0; j<n; j++){
		for (int i=0, len=0; i<m; i++){
			if (matrix[i][j]=='1') len++;
			else len=0;
			memo[i][j] = min(memo[i][j],len);
		}
		for (int i=m-1, len=0; i>=0; i--){
			if (matrix[i][j]=='1') len++;
			else len=0;
			memo[i][j] = min(memo[i][j],len);
			res = max(res, memo[i][j]);
		}
	}
	return res;
}
/*
int main(){
	vector<string> maze({"101011",
						 "111110",
						 "011111",
						 "100101",
						 "011110"});
	cout<<largest_crossing(maze);
	return 0;
}
*/




