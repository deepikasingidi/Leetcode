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
    vector<int> v1;
    void fun1(TreeNode* root1){
        if(root1 == NULL) return;
        if(root1->left == NULL && root1->right==NULL) v1.push_back(root1->val);
        fun1(root1->left);
        fun1(root1->right);
    }
    vector<int> v2;
    void fun2(TreeNode* root2){
        if(root2 == NULL) return;
        if(root2->left == NULL && root2->right==NULL) v2.push_back(root2->val);
        fun2(root2->left);
        fun2(root2->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        fun1(root1);
        fun2(root2);
        return v1 == v2;
    }
};