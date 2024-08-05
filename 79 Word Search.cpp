class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;

        m = board.size(), n = board[0].size();

        visited = vector<vector<bool>>(m, vector<bool>(n));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(exist(board, 0, i, j))
                    return true;
            }
        }

        return false;
    }

private:
    vector<vector<bool>> visited;
    string word;
    int m, n;

    bool exist(const vector<vector<char>>& board, int index, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[index])
            return false;

        if(index == word.length() - 1)
            return true;

        visited[i][j] = true;

        if(exist(board, index + 1, i - 1, j)) {
            visited[i][j] = false;
            return true;
        }

        if(exist(board, index + 1, i + 1, j)) {
            visited[i][j] = false;
            return true;
        }

        if(exist(board, index + 1, i, j - 1)) {
            visited[i][j] = false;
            return true;
        }

        if(exist(board, index + 1, i, j + 1)) {
            visited[i][j] = false;
            return true;
        }

        visited[i][j] = false;
        return false;
    }
};