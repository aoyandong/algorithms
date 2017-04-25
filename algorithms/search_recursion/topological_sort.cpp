/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> res;
        BFS_topSort(graph, res);
        return res;
    }

private:
    void BFS_topSort(vector<DirectedGraphNode*>& graph, vector<DirectedGraphNode*>& res){
        unordered_map<DirectedGraphNode*, int> mp;
        for (int i=0; i<graph.size(); i++) mp[graph[i]] = 0;
        for (int i=0; i<graph.size(); i++) 
            for (int j=0; j<graph[i]->neighbors.size(); j++)
                mp[graph[i]->neighbors[j]] ++;
        
        queue<DirectedGraphNode*> Q;
        for (auto it=mp.begin(); it!=mp.end(); it++)
            if (it->second==0) Q.push(it->first);
        
        DirectedGraphNode* cur;
        while (!Q.empty()){
            cur = Q.front();
            Q.pop();
            for (int i=0; i<cur->neighbors.size(); i++){
                mp[cur->neighbors[i]]--;
                if (mp[cur->neighbors[i]] == 0) Q.push(cur->neighbors[i]);
            }
            res.push_back(cur);
        }
    }
    
    void DFS_topSort(vector<DirectedGraphNode*>& graph, vector<DirectedGraphNode*>& res){
        unordered_map<DirectedGraphNode*, int> visited;
        stack<DirectedGraphNode*> S;
        for (int i=0; i<graph.size(); i++){
            if (visited.find(graph[i])==visited.end()){
                DFS_helper(graph[i], visited, S);
            }
        }
        
        while (!S.empty()){
            res.push_back(S.top());
            S.pop();
        }
    }
    
    void DFS_helper(DirectedGraphNode* cur, unordered_map<DirectedGraphNode*, int>& visited, stack<DirectedGraphNode*>& S){
        visited[cur] = 1;
        for (int i=0; i<cur->neighbors.size(); i++){
            if (visited.find(cur->neighbors[i])==visited.end()){
                DFS_helper(cur->neighbors[i], visited, S);
            }
        }
        S.push(cur);
    }};