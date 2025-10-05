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
    vector<double> averageOfLevels(TreeNode* root) {
        long long sum = 0,cnt=0;
        vector<double> vec;
        vec.push_back(root->val);

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    sum += node->left->val;
                    cnt++;
                }
                if(node->right){
                    q.push(node->right);
                    sum += node->right->val;
                    cnt++;
                }
            }
            vec.push_back((double)sum / cnt);
            sum = 0;
            cnt = 0;
        }
        vec.erase(vec.end());
        return vec;
    }
};