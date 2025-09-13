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
    void leftleaves(TreeNode* root, int& ans){
        if(root->left){
            leftleaves(root->left, ans);
        if(root->left->left == NULL && root->left->right == NULL) ans += root->left->val;
        }
        if(root->right) leftleaves(root->right, ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        leftleaves(root, ans);
        return ans;
    }
};