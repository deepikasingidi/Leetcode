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
    int ans = 0;
    void fun(TreeNode* root, int curr) {
        curr = curr << 1;

        if(root->val == 1) curr++;
        if(root->left == NULL && root->right == NULL) {
            ans += curr;
            return;
        }

        if(root->left) fun(root->left, curr);
        if(root->right) fun(root->right, curr);
    }
    int sumRootToLeaf(TreeNode* root) {
        int curr = (0>>1);
        fun(root, curr);
        return ans;
    }
};