class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }  
        
        vector<int> prev(n, -1);

        unordered_set<int> visited; visited.insert(0);

        int node;
        queue<int> pending; pending.push(0);
        while(!pending.empty()) {
            node = pending.front(); pending.pop();

            for(const int& v : adj[node]) {
                if(visited.find(v) != visited.end()) {
                    if(prev[node] != v)
                        return false;
                }
                else {
                    pending.push(v);
                    prev[v] = node;
                    visited.insert(v);
                }
            }
        }

        return (visited.size() == n);
    }
};