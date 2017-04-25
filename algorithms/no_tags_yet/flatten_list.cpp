/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
/*    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Recurrsive Solution.
        vector<int> res;
        for (int i=0; i<nestedList.size(); i++){
            if (nestedList[i].isInteger()){
                res.push_back(nestedList[i].getInteger());
            }
            else{
                vector<NestedInteger> tmp = nestedList[i].getList();
                vector<int> res_t = flatten(tmp);
                res.insert(res.end(),res_t.begin(),res_t.end());
            }
        }
        return res;
    }
*/    
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Iterative Solution
        stack<NestedInteger> S;
        vector<int> res;
        for (int i=0; i<nestedList.size(); i++) S.push(nestedList[i]);
        
        while (!S.empty()){
            NestedInteger tmp=S.top();
            S.pop();
            if (tmp.isInteger()) res.push_back(tmp.getInteger());
            else{
                vector<NestedInteger> nest_tmp = tmp.getList();
                for (int i=0; i<nest_tmp.size(); i++) S.push(nest_tmp[i]);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
