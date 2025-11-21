class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            dp[i][0] = 1;
            for(int j=1; j<=i; j++) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
        vector<int> res;
        for(int j=0; j<=n; j++) res.push_back(dp[n][j]);
        return res;
    }
};