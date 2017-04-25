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
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        int n = graph.size();
        unordered_set<DirectedGraphNode *> visited;
        
        return BFS(graph, s, t, visited);
    }

private:
    bool BFS(vector<DirectedGraphNode*> &graph,
                  DirectedGraphNode* s, DirectedGraphNode* t, unordered_set<DirectedGraphNode *> &visited){
        if (s==t) return true;
        for (int i=0; i<s->neighbors.size(); i++){
            if (visited.find(s->neighbors[i])==visited.end() && BFS(graph, s->neighbors[i], t, visited)) return true;
            else visited.insert(s->neighbors[i]);
        }
        return false;
    }
};

