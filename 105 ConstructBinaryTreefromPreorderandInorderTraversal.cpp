/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int root_index;
    vector<int> *pre;
    vector<int> *in;

    TreeNode* buildTree(int from, int to) {
        TreeNode *root = new TreeNode((*pre)[root_index]);

        if(from == to)
            return root;

        int center = from;
        while((*in)[center] != root->val)
            ++center;

        if(center - 1 >= from) {
            ++root_index;
            root->left = buildTree(from, center - 1);
        }

        if(center + 1 <= to) {
            ++root_index;
            root->right = buildTree(center + 1, to);
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        root_index = 0;

        pre = &preorder;
        in = &inorder;

        return buildTree(0, preorder.size() - 1);
    }
};