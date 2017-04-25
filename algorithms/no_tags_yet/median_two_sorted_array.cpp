// O(log(m+n)) solution. Not optimal.
class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
	// O(log(max(m,n))) Solution
	double findMedianSortedArrays(vector<int> A, vector<int> B) {
        int m = A.size();
        int n = B.size();
        if (m>n) return findMedianSortedArrays(B,A);
        
        int imin=0, imax=m, i,j, max_l, min_r;
        while (imin<=imax){
            i = imin + (imax-imin)/2;
            j = (m+n+1)/2 - i;
            if (i>0 && j<n && A[i-1]>B[j]) imax = i-1;
            else if (i<m && j>0 && B[j-1]>A[i]) imin = i+1;
            else{
                if (i==0) max_l = B[j-1];
                else if (j==0) max_l = A[i-1];
                else max_l = max(A[i-1],B[j-1]);
                
                if ((m+n)%2==1) return max_l;
                
                if (i==m) min_r = B[j];
                else if (j==n) min_r = A[i];
                else min_r = min(A[i],B[j]);
                return (min_r+max_l)/2.0;
            }
        }
    }

/*
	// O(log(m+n)) Solution
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        int t1 = getk(A,0,B,0,(A.size()+B.size()+1)/2);
        int t2 = getk(A,0,B,0,(A.size()+B.size()+2)/2);
        return (t1 + t2)/2.0;
    }
    
private:
    int getk(vector<int> &A, int Astart, vector<int> &B, int Bstart, int k){
        int m = A.size();
        int n = B.size();
        if (m-Astart>n-Bstart){
            return getk(B,Bstart,A,Astart,k);
        }
        if (m==Astart) return B[Bstart+k-1];
        if (k==1) return min(A[Astart],B[Bstart]);
        
        int i = min(m-Astart, k/2);
        int j = k/2;
        if (A[Astart+i-1]<B[Bstart+j-1]){
            return getk(A,Astart+i,B,Bstart,k-i);
        }
        else{
            return getk(A,Astart,B,Bstart+j,k-j);
        }
    }
*/
};

