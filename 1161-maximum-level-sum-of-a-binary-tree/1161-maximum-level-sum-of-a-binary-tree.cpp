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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        int res = 1;
        long long ans = root->val;
        while(!q.empty()) {
            int size = q.size();
            cnt++;
            long long sum = 0;
            for(int i=0; i<size; i++){
                auto top = q.front();
                sum += top->val;
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            if(sum > ans) {
                ans = sum;
                res = cnt;
            }
        }
        return res;
    }
};