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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;

        stack<TreeNode*> toInvert; toInvert.push(root);

        TreeNode *node;
        while(!toInvert.empty()) {
            node = toInvert.top();
            toInvert.pop();

            if(node->left)
                toInvert.push(node->left);
            if(node->right)
                toInvert.push(node->right);
            
            swap(node->left, node->right);
        }

        return root;
    }
};