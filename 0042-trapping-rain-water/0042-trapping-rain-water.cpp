class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> suffix(n);
        int prefix = height[0];
        suffix[n-1] = height[n-1];
        for(int j=n-2; j>=0; j--){
            suffix[j] = max(suffix[j+1], height[j]);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            prefix = max(prefix, height[i]);
            ans += min(prefix, suffix[i]) - height[i];
        }
        return ans;
    }
};