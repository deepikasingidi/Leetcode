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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        map<int, int> mp;
        int level=0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                mp[level] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        vector<int> res;
        for(auto it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};