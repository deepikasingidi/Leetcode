class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n+1, INT_MAX));
        dp[0][1] = triangle[0][0];
        for(int i=1; i<n; i++){
            for(int j=1; j<=triangle[i].size(); j++){
                dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j-1];
            }
        }
        int ans = INT_MAX;
        for(int i=1; i<n+1; i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};