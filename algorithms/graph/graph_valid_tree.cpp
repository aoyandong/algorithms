class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
     //For KK, try to slove with BFS and DFS too.
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        return Union_find(n,edges);
    }

private:
    bool Union_find(int n, vector<vector<int>>& edges){
        vector<int> roots(n,-1);
        for (int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            a = find_root(roots,a);
            b = find_root(roots,b);
            if (a==b) return false;
            roots[b] = a;
        }
        return edges.size()==(n-1); //check connectivity
    }
    int find_root(vector<int>&roots, int k){
        while (roots[k]!=-1) k=roots[k];
        return k;
    }
};