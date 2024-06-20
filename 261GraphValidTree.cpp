class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> adj(n, vector<bool>(n, false));
        for(int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]][edges[i][1]] = true;
            adj[edges[i][1]][edges[i][0]] = true;
        }  
        
        unordered_set<int> visited; visited.insert(0);

        int node;
        queue<int> pending; pending.push(0);
        while(!pending.empty()) {
            node = pending.front(); pending.pop();

            for(int i = 0; i < n; ++i) {
                if(adj[node][i]) {
                    if(visited.find(i) != visited.end())
                        return false;
                    
                    adj[i][node] = false;
                    pending.push(i);
                    visited.insert(i);
                }
            }
        }

        return (visited.size() == n);
    }
};