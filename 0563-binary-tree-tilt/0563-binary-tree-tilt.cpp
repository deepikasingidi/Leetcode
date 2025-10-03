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
    int sum = 0;
    int Tilt(TreeNode* root){
        if(root == NULL) return 0;
        int left = Tilt(root->left);
        int right = Tilt(root->right);
        sum += abs(left-right);
        return root->val+left+right;
    }
    int findTilt(TreeNode* root) {
        Tilt(root);
        return sum;
    }
};