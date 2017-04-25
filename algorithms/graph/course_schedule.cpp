class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> courses(numCourses); // save this directed graph
        for(int i=0; i<prerequisites.size(); i++)
            courses[prerequisites[i].second].insert(prerequisites[i].first);
        //return BFS(numCourses, courses);
        
        vector<bool> visited(numCourses,false), cur(numCourses,false);
        for (int i=0; i<numCourses; i++){
            if (!visited[i] && DFS(courses, i, visited, cur)) return false;
        }
        return true;
    }
    
private:
    bool BFS(int numCourses, vector<unordered_set<int> > &courses){
        vector<int> indegree(numCourses,0);
        for (int i=0; i<courses.size(); i++)
            for (auto it:courses[i]) indegree[it]++;
        for (int i=0; i<numCourses; i++){ //every loop remove one course that has either fulfilled prerequisites or without prerequisites
            int j;
            for (j=0; j<numCourses; j++) 
                if (indegree[j]==0) break;
            if (j==numCourses) return false;
            indegree[j] = -1;
            for (auto it:courses[j]) indegree[it]--;
        }
        return true;
    }
    
    bool DFS(vector<unordered_set<int> > &courses, int c, vector<bool> &visited, vector<bool> &cur){
        visited[c] = true;
        cur[c] = true;
        for (auto it : courses[c]){
            if (cur[it] || DFS(courses,it,visited,cur)) return true;
        }
        cur[c] = false;
        return false;
    }
};
