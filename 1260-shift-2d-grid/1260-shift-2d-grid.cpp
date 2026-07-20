class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        while(k--) {
            int val = grid[n-1][m-1];
            for(int i=n-1; i>=0; i--){
                for(int j=m-1; j>0; j--){
                    grid[i][j] = grid[i][j-1];
                }
                if(i!=0) grid[i][0] = grid[i-1][m-1];
                else grid[i][0] = val;
            }
        }
        return grid;
    }
};