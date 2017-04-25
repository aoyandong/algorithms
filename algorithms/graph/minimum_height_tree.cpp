class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> adj(n);
        for (int i=0; i<edges.size(); i++){
            adj[edges[i].first].insert(edges[i].second);
            adj[edges[i].second].insert(edges[i].first);
        }
        
        vector<int> res;
        if (n==1) {return vector<int>(1,0);}
        for (int i=0; i<adj.size(); i++){ //push leaves
            if (adj[i].size()==1) res.push_back(i);
        }
        while (true){
            vector<int> tmp;
            for (int i=0; i<res.size(); i++){
                for (auto it:adj[res[i]]){
                    adj[it].erase(res[i]);
                    if (adj[it].size()==1) tmp.push_back(it);
                }
            }
            if (tmp.size()==0) return res;
            res = tmp;
        }
    }
};