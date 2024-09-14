class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);

        for(const vector<int>& prereq : prerequisites)
            graph[prereq[0]].push_back(prereq[1]);

        visited.resize(numCourses);
        exploreVisited.resize(numCourses);

        for(int i = 0; i < numCourses; ++i) {
            if(!visited[i] && !dfs(i))
                return false;
        }

        return true;
    }

private:
    vector<vector<int>> graph;
    vector<bool> visited, exploreVisited;

    bool dfs(int course) {
        visited[course] = true; 
        
        exploreVisited[course] = true;

        for(const int& prereq : graph[course]) {
            if(exploreVisited[prereq] || ( !visited[prereq] && !dfs(prereq) ))
                return false;
        }

        exploreVisited[course] = false;

        return true;
    }
};