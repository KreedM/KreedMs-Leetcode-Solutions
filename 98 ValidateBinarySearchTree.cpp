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
    // vector<int> nodes;

    // void dfs(TreeNode *node) {
    //     if(!node)
    //         return;

    //     dfs(node->left);

    //     nodes.push_back(node->val);

    //     dfs(node->right);
    // }

    // bool isValidBST(TreeNode* root) {
    //     dfs(root);

    //     int n = nodes.size();
    //     for(int i = 1; i < n; ++i) {
    //         if(nodes[i] <= nodes[i - 1])
    //             return false;
    //     }

    //     return true;
    // }

    long prev = INT_MIN - 1L;

    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        if(isValidBST(root->left)) {
            if(root->val <= prev)
                return false;
            else {
                prev = root->val;
                
                return isValidBST(root->right);
            }
        }
        else
            return false;
    }
};