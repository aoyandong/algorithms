class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> courses(numCourses);
        for (auto pre : prerequisites)
            courses[pre.second].insert(pre.first);
            
        vector<int> res;
        vector<int> indegree(numCourses,0);
        for (int i=0; i<numCourses; i++)
            for (auto it:courses[i]) indegree[it]++;
        
        for (int i=0, j; i<numCourses; i++){
            for (j=0; j<numCourses; j++)
                if (indegree[j]==0) break;
            if (j==numCourses) return vector<int>();
            res.push_back(j);
            indegree[j]=-1;
            for (auto it:courses[j]) indegree[it]--;
        }
        return res;
    }
};
