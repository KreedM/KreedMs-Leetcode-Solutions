class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        this->word = word;
        this->board = &board;

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(exist(0, i, j))
                    return true;
            }
        }

        return false;
    }

private:
    int m, n;
    string word;
    vector<vector<bool>> visited;
    vector<vector<char>> *board;

    bool exist(int index, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || (*board)[i][j] != word[index])
            return false;

        if(index == word.length() - 1)
            return true;

        visited[i][j] = true;

        bool up = exist(index + 1, i - 1, j);
        bool down = exist(index + 1, i + 1, j);
        bool left = exist(index + 1, i, j - 1);
        bool right = exist(index + 1, i, j + 1);

        visited[i][j] = false;
        return up || down || left || right;
    }
};