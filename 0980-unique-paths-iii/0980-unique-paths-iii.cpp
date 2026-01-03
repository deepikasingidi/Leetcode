class Solution {
public:
    int fun(vector<vector<int>> &grid,int n,int m,int i,int j,int zero,int cnt, vector<vector<int>> &vis) {
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(grid[i][j] == -1 || vis[i][j]==1) return 0;

        if(grid[i][j]==2 && cnt==zero) return 1;

        vis[i][j] = 1;
        if(grid[i][j] == 0) cnt++;

        int top = fun(grid, n, m, i-1, j, zero, cnt,vis);
        int bottom = fun(grid, n, m, i+1, j, zero, cnt,vis);
        int left = fun(grid, n, m, i, j-1, zero, cnt,vis);
        int right = fun(grid, n, m, i, j+1, zero, cnt,vis);

        vis[i][j] = -1;

        return top+bottom+left+right;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int zero = 0;
        int si, sj;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) zero++;
                if(grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
            }
        }

        vector<vector<int>> vis(n, vector<int>(m, -1));
        int ans = fun(grid, n, m, si, sj, zero, 0, vis);
        return ans;
    }
};