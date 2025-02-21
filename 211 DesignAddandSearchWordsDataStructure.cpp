class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    ~WordDictionary() {
        delete root;
    }
    
    void addWord(string word) {
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
        return search(root, word.c_str());
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

    bool search(TrieNode *node, const char *curr) {
        if(*curr == '\0')
            return false;

        if(*curr == '.') {
            for(int i = 0; i < 26; ++i) {
                if(node->children[i]) {
                    if(*(curr + 1) == '\0' && node->children[i]->isWord)
                        return true;
                    else if(search(node->children[i], curr + 1))
                        return true;
                }
            }

            return false;
        }
        else {
            char c = *curr - 'a';
            
            if(node->children[c]) {
                if(*(curr + 1) == '\0')
                    return node->children[c]->isWord;
                else
                    return search(node->children[c], curr + 1);
            }
            else
                return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */