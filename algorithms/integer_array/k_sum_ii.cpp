class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    //For KK: this is exactly the slow version of ksum, with backtracking which you will practice in Level 8 "search and recursion".

    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        sort(A.begin(),A.end());
        vector<vector<int> > res;
        vector<int> cur;
        
        if (A.size()<k) return res;
        kSum_helper(A,k,target,0, res,cur);
        
        return res;
    }
    
    void kSum_helper(vector<int> &A, int k, int target, int start, vector<vector<int> >&res, vector<int> &cur){
        int n=A.size();
        if (k==1){
            for (int i=0; i<A.size(); i++){
                if (A[i]==target) {
                    res.push_back(vector<int>(1,target));
                    return;
                }
            }
        }
        else if (k==2){
            int i=start, j=n-1;
            if (A[i]+A[i+1]>target || A[j]+A[j-1]<target) return;
            while (i<j){
                if (A[i]+A[j]==target) {
                    cur.push_back(A[i]);
                    cur.push_back(A[j]);
                    res.push_back(cur);
                    cur.pop_back();
                    cur.pop_back();
                    i++; j--;
                }
                else if (A[i]+A[j]<target) i++;
                else j--;
            }
            return;
        }
        else{
            int cur_min=0, cur_max=0;
            for (int j=0; j<k; j++) cur_min += A[start+j];
            for (int j=1; j<k; j++) cur_max += A[n-j]; 
            
            for (int i=start; i<n-k+1; i++){
                if (i!=start) cur_min = cur_min-A[i-1]+A[i+k-1];
                if (cur_min>target) break;
                if (A[i]+cur_max<target) continue;
                
                cur.push_back(A[i]);
                kSum_helper(A,k-1,target-A[i],i+1,res,cur);
                cur.pop_back();
            }
        }
    }
};

