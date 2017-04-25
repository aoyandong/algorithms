class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0, n = citations.size();
        if (n==0 || citations[n-1]==0) return 0;
        
        int lo=0, hi=n-1;
        while (lo<hi){
            int mid = lo + (hi-lo)/2;
            if (citations[mid]<n-mid) lo=mid+1;
            else hi = mid;
        }
        return n-lo;
    }
};
