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
    int count = 0;

    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return 0;

        int l = kthSmallest(root->left, k);

        if(count == k)
            return l;
        else if(++count == k)
            return root->val;
        else
            return kthSmallest(root->right, k);
    }
};