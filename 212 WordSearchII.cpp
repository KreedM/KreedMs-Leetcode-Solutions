class TrieNode {
    public:
        TrieNode* children[26];
        string *word;

        TrieNode() {
            for(int i = 0; i < 26; ++i)
                children[i] = nullptr;
            
            word = nullptr;
        }

        ~TrieNode() {
            for(int i = 0; i < 26; ++i)
                delete children[i];
        }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->board = &board;
        root = new TrieNode;
        on_board.clear();

        for(string& word : words) {
            TrieNode *node = root;

            for(char c : word) {
                if(node->children[c - 'a'] == nullptr)
                    node->children[c - 'a'] = new TrieNode;

                node = node->children[c - 'a'];
            }

            node->word = &word;
        }

        m = board.size(), n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j)
                traverse(root, i, j);
        }

        delete root;

        return on_board;
    }

private:
    vector<vector<char>> *board;
    TrieNode *root;
    vector<string> on_board;

    int m, n;
    vector<vector<bool>> visited;

    void traverse(TrieNode *node, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
            return;

        TrieNode *curr = node->children[(*board)[i][j] - 'a'];
        if(curr == nullptr)
            return;

        if(curr->word) {
            on_board.push_back(*(curr->word));
            curr->word = nullptr;
        }

        visited[i][j] = true;

        traverse(curr, i - 1, j);
        traverse(curr, i + 1, j);
        traverse(curr, i, j - 1);
        traverse(curr, i, j + 1);

        visited[i][j] = false;
    }
};