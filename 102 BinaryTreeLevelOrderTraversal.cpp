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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return vector<vector<int>>();

        queue<TreeNode*> q; q.push(root);

        vector<vector<int>> traversal;
        while(!q.empty()) {
            vector<int> level(q.size());

            for(int& val : level) {
                TreeNode *node = q.front(); q.pop();

                val = node->val;

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

            traversal.push_back(level);
        }

        return traversal;
    }
};