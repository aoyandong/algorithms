/*
 * task_distribute.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: day
 */
#include "../everything.h"
using namespace std;
/*
class Solution {
public:
    int distribute(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        vector<int> workers(k,0);
        int best = INT_MAX;
        helper(nums, workers, 0, best);
        return best;
    }

    void helper(vector<int>& nums, vector<int>& workers, int idx, int& best){
        if (idx==nums.size()){
        	int cur=INT_MIN;
        	for (int i=0; i<workers.size(); i++) cur = max(cur, workers[i]);
        	best = min(best, cur);
        	return;
        }
        for (int k=0; k<workers.size(); k++){
            workers[k] += nums[idx];
            helper(nums,workers, idx+1, best);
            workers[k] -= nums[idx];
        }
    }
};
*/

void helper(vector<int>& tasks, vector<int>& workers, int idx, int& best){
	if (idx==tasks.size()){
		int res=0;
		for (int i=0; i<workers.size(); i++){
			res = max(res, workers[i]);
		}
		best = min(best, res);
		return;
	}
	for (int i=0; i<workers.size(); i++){
		if (workers[i]+tasks[idx]>=best) continue;
		workers[i] += tasks[idx];
		helper(tasks, workers, idx+1, best);
		workers[i] -= tasks[idx];
	}
}

int distributeTask(vector<int>& tasks, int K){
	sort(tasks.rbegin(),tasks.rend());
	vector<int> workers(K,0);
	int best=INT_MAX;
	helper(tasks, workers, 0, best);
	return best;
}
/*
int main(){
	vector<int> tasks({9,8,7,4,4});
	cout<<distributeTask(tasks,2)<<endl;
	return 0;
}

*/
