/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if (node==NULL) return node;
        
        if (map.find(node)==map.end()){
            map[node] = new UndirectedGraphNode(node->label);
            for (int i=0; i<node->neighbors.size(); i++){
                (map[node]->neighbors).push_back(cloneGraph(node->neighbors[i]));
            }
        }
        return map[node];
    }
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
};
