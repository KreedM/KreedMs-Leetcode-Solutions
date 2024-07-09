class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size(); 
        island = vector<vector<int>>(m, vector<int>(n, 0));

        islands = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1' && !island[i][j]) {
                    island[i][j] = ++islands;
                    floodfill(grid, i, j);
                }
            }
        }

        return islands;
    }

private:
    int m, n, islands;
    vector<vector<int>> island;

    void floodfill(const vector<vector<char>>& grid, const int& i, const int& j) {
        if(i + 1 < m && grid[i + 1][j] == '1' && !island[i + 1][j]) {
            island[i + 1][j] = island[i][j];
            floodfill(grid, i + 1, j);
        }

        if(i - 1 >= 0 && grid[i - 1][j] == '1' && !island[i - 1][j]) {
            island[i - 1][j] = island[i][j];
            floodfill(grid, i - 1, j);
        }

        if(j + 1 < n && grid[i][j + 1] == '1' && !island[i][j + 1]) {
            island[i][j + 1] = island[i][j];
            floodfill(grid, i, j + 1);
        }

        if(j - 1 >= 0 && grid[i][j - 1] == '1' && !island[i][j - 1]) {
            island[i][j - 1] = island[i][j];
            floodfill(grid, i, j - 1);
        }
    }
};