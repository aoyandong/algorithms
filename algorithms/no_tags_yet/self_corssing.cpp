class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size()<=3) return false;
        for (int i=0; i<(x.size()-3); i++){
            if (x[i]>=x[i+2] && x[i+1]<=x[i+3]) return true;
            if (i+3<x.size()-1 && x[i]+x[i+4]>=x[i+2] && x[i+1]==x[i+3]) return true;
            if (i+4<x.size()-1 && x[i]+x[i+4]>=x[i+2] && x[i+4]<x[i+2] && x[i+1]+x[i+5]>=x[i+3] && x[i+1]<x[i+3]) return true;
        }
        return false;
    }
};
