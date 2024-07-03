class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(); n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));

        for(int i = 0; i < m; ++i) {
            if(!pacific[i][0])
                dfs(heights, pacific, i, 0);
        }

        for(int i = 1; i < n; ++i) {
            if(!pacific[0][i])
                dfs(heights, pacific, 0, i);
        }

        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int i = 0; i < m; ++i) {
            if(!atlantic[i][n - 1])
                dfs(heights, atlantic, i, n - 1);
        }

        for(int i = 0; i < n - 1; ++i) {
            if(!atlantic[m - 1][i])
                dfs(heights, atlantic, m - 1, i);
        }

        vector<vector<int>> both;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(pacific[i][j] && atlantic[i][j])
                    both.push_back({i, j});
            }
        }

        return both;
    }

private:
    int m, n;

    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& ocean, const int& r, const int& c) {
        ocean[r][c] = true;

        if(r > 0 && !ocean[r - 1][c] && heights[r][c] <= heights[r - 1][c])
            dfs(heights, ocean, r - 1, c);
        
        if(c > 0 && !ocean[r][c - 1] && heights[r][c] <= heights[r][c - 1])
            dfs(heights, ocean, r, c - 1);

        if(r < m - 1 && !ocean[r + 1][c] && heights[r][c] <= heights[r + 1][c])
            dfs(heights, ocean, r + 1, c);

        if(c < n - 1 && !ocean[r][c + 1] && heights[r][c] <= heights[r][c + 1])
            dfs(heights, ocean, r, c + 1);
    }
};