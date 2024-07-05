/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        tree.clear();

        preorder(root);

        ostringstream oss;

        if (!tree.empty())
        {
            copy(tree.begin(), tree.end() - 1, ostream_iterator<int>(oss, ","));
            oss << tree.back();
        }

        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        tree.clear();

        istringstream iss(data);

        string token;
        while(getline(iss, token, ','))
            tree.push_back(stoi(token));

        int i = 0;
        return makeTree(i);
    }

private:
    vector<int> tree;

    void preorder(TreeNode* node) {
        if(node) {
            tree.push_back(node->val);
            preorder(node->left);
            preorder(node->right);
        }
        else
            tree.push_back(-1);
    }

    TreeNode* makeTree(int& i) {
        if(tree[i] == -1) {
            ++i;            
            return nullptr;
        }

        TreeNode* node = new TreeNode(tree[i++]);

        node->left = makeTree(i);
        node->right = makeTree(i);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;