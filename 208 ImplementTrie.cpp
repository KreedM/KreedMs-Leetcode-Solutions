class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        TrieNode *node = root;

        for(char c : word) { 
            c -= 'a';

            if(node->children[c])
                node = node->children[c];
            else {
                node->children[c] = new TrieNode();
                node = node->children[c];
            }
        }

        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;

        for(char c : word) {
            c -= 'a';

            if(node->children[c])
                node = node->children[c];
            else
                return false;
        }

        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;

        for(char c : prefix) { 
            c -= 'a';

            if(node->children[c])
                node = node->children[c];
            else
                return false;
        }

        return dfsWord(node);
    }
private:
    class TrieNode {
    public:
        TrieNode() { 
            isWord = false; 

            for(int i = 0; i < 26; ++i)
                children[i] = nullptr;
        }

        ~TrieNode() {
            for(int i = 0; i < 26; ++i) {
                if(children[i])
                    delete children[i];
            }
        }

        bool isWord;
        TrieNode* children[26];
    };

    TrieNode *root;

    bool dfsWord(TrieNode *node) {
        if(node->isWord)
            return true;
        else {
            for(int i = 0; i < 26; ++i) {
                if(node->children[i] && dfsWord(node->children[i]))
                    return true;
            }

            return false;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */