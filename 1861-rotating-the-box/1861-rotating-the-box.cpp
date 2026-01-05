class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++) {
            int p1=0, p2=0;
            while(p1<m && p2 < m) {
                if(grid[i][p2] == '*') p1=p2;
                if(grid[i][p1] == '#' && p2<p1) p2 = p1;

                if(grid[i][p1] != '#') p1++;
                if(grid[i][p2] != '.') p2++;
                
                if(p1<m && p2<m && p1<p2 && grid[i][p1]=='#' && grid[i][p2]=='.'){
                    swap(grid[i][p1], grid[i][p2]);
                    cout << p1 << " " << p2 << endl;
                }
            }
        }

        // return grid;

        vector<vector<char>> res(m, vector<char>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res[i][n-1-j] = grid[j][i];
            }
        }
        return res;
    }
};