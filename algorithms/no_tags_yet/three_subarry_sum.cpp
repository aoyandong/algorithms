/*
 * three_subarry_sum.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: day
 */

#include "everything.h"
using namespace std;

int findNWindow(vector<int>& nums, int K, int n){
	int m = nums.size();
    vector<int> lastMaxK(m,0);
    vector<int> maxK(m,0);

    for(int i=0; i<n; i++){
    	int curSum=0;
    	for(int j=i*K; j<m; j++){
    		curSum += nums[j];

    		if (j<(i+1)*K-1) continue;
    		if (j>=(i+1)*K) curSum -= nums[j-K];

    		if (j==K-1) maxK[j] = curSum;
    		else maxK[j] = max(lastMaxK[j-K] + curSum, maxK[j-1]);
    	}
    	swap(maxK, lastMaxK);
    	for (auto x:lastMaxK) cout<<x<<'\t';
    	cout<<endl;
    }

    return lastMaxK[m-1];
}

vector<int> sumlength_K(vector<int>& nums, int K){
	int n = nums.size();
	int sum = 0;
	vector<int> res;
	for (int i=0; i<K; i++) sum += nums[i];
	res.push_back(sum);
	for (int i=K; i<n; i++) {
		sum += nums[i]-nums[i-K];
		res.push_back(sum);
	}
	return res;
}

int three_non_overlappingK(vector<int>& nums, int K, int& sep1, int& sep2){
	int n=nums.size();
	if (n<3*K) return 0;
	vector<int> sum = sumlength_K(nums,K);
	vector<vector<int>> memo(n,vector<int>(n,0)); // maxsum from i->j (inclusive)
	for (int i=0; i<n; i++){
		for (int j=i+K-1; j<n; j++){
			memo[i][j] = max(memo[i][j-1],sum[j-K+1]);
		}
	}
	int res = INT_MIN;
	for (int i=K; i<=n-2*K; i++){
		for (int j=i+K; j<=n-K; j++){
			if (res < memo[0][i-1]+memo[i][j-1]+memo[j][n-1]){
				res = memo[0][i-1]+memo[i][j-1]+memo[j][n-1];
				sep1 = i;
				sep2 = j;
			}
		}
	}
	/*
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout<<memo[i][j]<<'\t';
		}
		cout<<endl;
	}
	cout<<endl;
	*/
	return res;
}
/*
int main(){
	int n = 12;
	vector<int> data;
	srand(time(NULL));
	for (int i=0; i<n; i++) cout<<i<<'\t';
	cout<<endl;
	for (int i=0; i<n; i++){
		data.push_back(rand()%n);
		cout<<data[i]<<'\t';
	}
	cout<<endl<<endl;
	int sep1, sep2;
	cout<<three_non_overlappingK(data,4, sep1, sep2)<<endl;
	cout<<sep1<<' '<<sep2;

	cout<<endl;
	cout<<findNWindow(data,4,3)<<endl;
	return 0;
}
*/
