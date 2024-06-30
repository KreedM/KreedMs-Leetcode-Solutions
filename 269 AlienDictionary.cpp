class Solution {
public:
    unordered_map<char, vector<char>> graph; // Could use 2D vector for adjacency list
    unordered_map<char, int> visited;
    int orderNum;

    void explore(const char& v) {
        visited[v];
        
        for(const char& e : graph[v]) {
            if(visited.find(e) == visited.end())
                explore(e);
        }

        visited[v] = --orderNum;
    }

    string foreignDictionary(vector<string>& words) {
        for(const string& s : words) { // Create vertices
            for(const char& c : s)
                graph[c];
        }

        for(int i = 0; i < words.size() - 1; ++i) { // Create edges
            bool earlyBreak = false;

            for(int j = 0; j < words[i].length() && j < words[i + 1].length(); ++j) {
                char a = words[i][j], b = words[i + 1][j];

                if(a != b)  {
                    graph[a].push_back(b);
                    earlyBreak = true;
                    break;
                }
            }

            if(!earlyBreak && words[i].length() > words[i + 1].length())
                return "";
        }

        orderNum = graph.size();
        visited.reserve(orderNum);

        string s(orderNum, ' ');

        for(const auto& v : graph) { // DFS
            if(visited.find(v.first) == visited.end())
                explore(v.first);
        }

        for(const auto& v : graph) { // Check for cycles
            for(const char& c : v.second) {
                if(visited[v.first] > visited[c])
                    return "";
            }
        }

        for(const auto& v : visited)
            s[v.second] = v.first;

        return s;
    }
};
