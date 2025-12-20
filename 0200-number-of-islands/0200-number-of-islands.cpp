class Solution {
public:
    void dfs(vector<vector<char>> & grid,int i,int j,int n,int m) {
        queue<pair<int, int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        while(!q.empty()) {
            auto top = q.front();
            int i1 = top.first;
            int j1 = top.second;
            q.pop();
            if(i1-1 >= 0 && grid[i1-1][j1] == '1'){
                q.push({i1-1, j1});
                grid[i1-1][j1] = '0';
            }
            if(i1+1 < n && grid[i1+1][j1] == '1'){
                q.push({i1+1, j1});
                grid[i1+1][j1] = '0';
            }
            if(j1-1 >= 0 && grid[i1][j1-1] == '1'){
                q.push({i1, j1-1});
                grid[i1][j1-1] = '0';
            }
            if(j1+1 < m && grid[i1][j1+1] == '1'){
                q.push({i1, j1+1});
                grid[i1][j1+1] = '0';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};