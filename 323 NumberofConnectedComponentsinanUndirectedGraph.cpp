class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int cc = 0, node;
        vector<bool> visited(n);
        stack<int> dfs;
        for(int i = 0; i < n; ++i) {
            if(visited[i])
                continue;

            ++cc;

            dfs.push(i); visited[i] = true;
            while(!dfs.empty()) {
                node = dfs.top(); dfs.pop();

                for(const int& edge : graph[node]) {
                    if(!visited[edge]) {
                        dfs.push(edge);
                        visited[edge] = true;
                    }
                }
            }
        }

        return cc;
    }
};