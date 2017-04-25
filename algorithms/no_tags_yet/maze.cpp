/*
 * maze.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: day
 */
#include "everything.h"
using namespace std;

struct npc{
	int x, y, power;
	npc(int _x, int _y, int _power): x(_x), y(_y), power(_power){}
};

int shortest_path_with_magic(vector<string>& maze, int magic, int s, int e){
	int m = maze.size();
	int n = maze[0].length();
	vector<vector<int>> memo(m, vector<int>(n,-1));
	queue<npc> Q;
	Q.push(npc(s,e,magic));
	memo[s][e] = magic;
	int res=0;
	int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
	while (!Q.empty()){
		int K = Q.size();
		for (int k=0; k<K; k++){
			npc cur = Q.front();
			int i = cur.x, j = cur.y;
			Q.pop();
			if (maze[i][j]=='E') return res;
			for (int t=0; t<4; t++){
				int ii = i+dirs[t][0], jj = j+dirs[t][1];
				int power = cur.power;
				while (ii>=0 && jj>=0 && ii<m && jj<n && maze[ii][jj]=='X'){
					ii += dirs[t][0];
					jj += dirs[t][1];
					power--;
					if (power<0) break;
				}
				if (ii<0 || jj<0 || ii>=m || jj>=n || power<0) continue;
				if (power>memo[ii][jj]){
					memo[ii][jj] = power;
					Q.push(npc(ii,jj,power));
				}
			}
		}
		res++;
	}
	return -1;
}
/*
int main(){
	vector<string> maze({"OXXXXE",
						 "OXOXXO",
						 "OXOOXX",
						 "OOOXXX"});
	cout<<shortest_path_with_magic(maze, 2, 0, 0);
	return 0;
}
*/

