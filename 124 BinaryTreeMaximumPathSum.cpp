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
    int maxPathSumHelper(TreeNode* root) { // Returns max path with root being first or last in sequence
        if(root == nullptr)
            return 0;

        int l = maxPathSumHelper(root->left), r = maxPathSumHelper(root->right);

        maxPath = max(maxPath, root->val);
        maxPath = max(maxPath, root->val + l);
        maxPath = max(maxPath, root->val + r);
        maxPath = max(maxPath, root->val + l + r);

        return max(root->val, max(root->val + l, root->val + r));
    }

    int maxPathSum(TreeNode* root) {
        maxPath = root->val;

        maxPathSumHelper(root);

        return maxPath;
    }

private:
    int maxPath;
};