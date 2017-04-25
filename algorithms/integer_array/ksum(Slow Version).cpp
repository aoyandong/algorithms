class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */

    // For KK: 
    // This is a generalized version of 2sum, 3sum, 4sum problem. 
    // However, it is slow: (O(N^(k-1)). I tried hard to optimize this, but failed. :(

    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        sort(A.begin(),A.end());
        int res=0;
        if (A.size()<k) return res;
        
        res = kSum_helper(A,k,target,0);
        
        return res;
    }

    int kSum_helper(vector<int> &A, int k, int target, int start){
        int n=A.size();
        int res=0;
        if (k==1){
            for (int i=0; i<A.size(); i++){
                if (A[i]==target) return 1;
            }
        }
        else if (k==2){
            int i=start, j=n-1;
            if (A[i]+A[i+1]>target || A[j]+A[j-1]<target) return 0;
            while (i<j){
                if (A[i]+A[j]==target) {
                    res++; i++; j--;
                }
                else if (A[i]+A[j]<target) i++;
                else j--;
            }
            return res;
        }
        else {
            int cur_min=0, cur_max=0;
            for (int j=0; j<k; j++) cur_min += A[start+j];
            for (int j=1; j<k; j++) cur_max += A[n-j]; 
            
            for (int i=start; i<n-k+1; i++){
                if (i!=start) cur_min = cur_min-A[i-1]+A[i+k-1];
                if (cur_min>target) break;
                if (A[i]+cur_max<target) continue;
                
                res = res + kSum_helper(A,k-1,target-A[i],i+1);
            }
        }
        return res;
    }
};
