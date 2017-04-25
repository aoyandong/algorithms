class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> tmp;
        vector<int> res;
        if (k==0) return res;
        
        for (int i=0; i<=k; i++){
            if (i>nums1.size()||k-i>nums2.size()) continue;
            tmp = combineMax(getMax(nums1,i),getMax(nums2,k-i));
            if (res.size()==0) swap(res,tmp);
            else{
                for (int j=0; j<tmp.size(); j++){
                    if (tmp[j]>res[j]) { swap(tmp,res); break; }
                    else if (tmp[j]<res[j]) break;
                }
            }
        }
        return res;
    }

private:
    vector<int> getMax(vector<int>& nums, int t){
        vector<int> res(t,0);
        int i=0, j=0, n=nums.size();
        for (i=0; i<n; i++){
            while (n-i+j>t && j>0 && res[j-1]<nums[i]) j--;
            if (j<t) {res[j] = nums[i]; j++;}
        }
        return res;
    }
/*
    vector<int> getMax(vector<int>& nums, int t){
        vector<int> res;
        if (t==0) return res;
        int n = nums.size();
        stack<int> stk;
        int count=0;
        for (int i=0; i<n; i++){
            while (!stk.empty() && stk.top()<nums[i] && count<n-t){
                stk.pop();
                count++;
            }
            stk.push(nums[i]);
        }
        for (int i=0; i<n-t-count;i++) stk.pop();
        while (!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
*/    
    vector<int> combineMax(vector<int> A, vector<int> B){
        vector<int> res(A.size()+B.size(),0);
        int i=0, j=0;
        for(int i=0, j=0, k=0; k<A.size()+B.size(); k++ ){
            if (compare(A,i,B,j)) {res[k]=A[i]; i++;}
            else {res[k]=B[j]; j++;}
        }
        return res;
    }
    
    bool compare(vector<int> &A, int i, vector<int> &B, int j){
        while (i<A.size() && j<B.size() && A[i]==B[j]){ i++; j++; }
        if (j==B.size() || (i!=A.size()&&A[i]>B[j])) return true;
        else return false;
    }
};
