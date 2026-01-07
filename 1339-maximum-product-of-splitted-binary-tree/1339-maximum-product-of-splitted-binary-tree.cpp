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
    vector<long long> vec;
    long long maxi = LLONG_MIN;
    long long mod = 1e9+7;
    long long fun(TreeNode* root) {
        if(root == NULL) return 0;
        long long left = fun(root->left);
        long long right = fun(root->right);
        long long sum = ((root->val+left)%mod + right%mod)%mod;
        vec.push_back(sum);
        maxi = max(maxi, sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        fun(root);
        long long ans = 0;
        for(int i=0; i<vec.size(); i++){
            long long v1 = vec[i];
            long long v2 = (maxi - vec[i]);
            ans = max(ans, (v1*v2));
        }
        return ans%mod;
    }
};