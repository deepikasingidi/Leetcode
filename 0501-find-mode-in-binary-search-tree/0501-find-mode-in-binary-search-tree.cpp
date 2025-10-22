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
    map<int, int> mp;
    int maxi = 0;
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root->left);
        mp[root->val]++;
        maxi = max(maxi, mp[root->val]);
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        vector<int> res;
        for(auto it : mp){
            if(it.second == maxi) res.push_back(it.first);
        }
        return res;
    }
};