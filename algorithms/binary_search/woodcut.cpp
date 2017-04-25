class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
    	int N = L.size();
    	int length = 0;
    	for (int i=0; i<N; i++){
    		if (L[i]>length) length = L[i];
    	}
    	int front = 0, back = length;
    	int mid,count;
    	while ((front+1)<back){
    		mid = front+(back-front)/2;
    		count = getCount(L,mid);
    		if (count>=k) front = mid;
    		else back = mid;
    	}
    	if (getCount(L,back)>=k) return back;
    	else return front;
    }
    int getCount(vector<int>L, int length){
    	int count = 0;
    	for (int i=0; i<L.size(); i++){
    		count += L[i]/length;
    	}
    	return count;
    }
};