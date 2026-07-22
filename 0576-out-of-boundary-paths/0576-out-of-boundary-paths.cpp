class Solution {
public:
    vector<vector<vector<int>>> dp;
    int mod = 1e9+7;
    int fun(int m, int n, int max, int i, int j) {
        if(max == -1) return 0;

        if(i<0 || i>=m || j<0 || j>=n) return 1;
        if(dp[i][j][max] != -1) return dp[i][j][max];

        long long left = fun(m, n, max-1, i, j-1) % mod;
        long long right = fun(m, n, max-1, i, j+1) % mod;
        long long top = fun(m, n, max-1, i-1, j) % mod;
        long long bottom = fun(m, n, max-1, i+1, j) % mod;

        return dp[i][j][max] = (1LL * (left + right + top + bottom)) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return fun(m, n, maxMove, startRow, startColumn);
    }
};