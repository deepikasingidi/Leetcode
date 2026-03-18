class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pref(n, vector<int>(m));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(j==0) pref[i][j] = grid[i][j];
                else pref[i][j] = pref[i][j-1] + grid[i][j];
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i!=0) pref[i][j] = pref[i-1][j] + pref[i][j];
                if(pref[i][j] <= k) ans++;
            }
        }
        return ans;
    }
};