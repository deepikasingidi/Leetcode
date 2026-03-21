class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> vec(k, vector<int>(k));
        int i1=0, j1=0;
        for(int i=x+k-1; i>=x; i--) {
            j1 = 0;
            for(int j=y; j<y+k; j++) {
                vec[i1][j1] = grid[i][j];
                j1++;
            }
            i1++;
        }

        for(int i=0; i<k; i++) {
            for(int j=0; j<k; j++) {
                grid[i+x][j+y] = vec[i][j];
            }
        }
        return grid;
    }
};