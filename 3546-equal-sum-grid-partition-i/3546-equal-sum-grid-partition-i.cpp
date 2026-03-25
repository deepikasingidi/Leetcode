class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> hori(n, vector<long long>(m));
        long long total = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(j==0) hori[i][j] = grid[i][j];
                else hori[i][j] = hori[i][j-1] + grid[i][j];
                total += grid[i][j];
            }
        }
        long long sum = 0;
        for(int i=0; i<n; i++) {
            sum += hori[i][m-1];
            if(sum == total-sum) return true;
        }
        
        vector<vector<long long>> verti(n, vector<long long>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0) verti[i][j] = grid[i][j];
                else verti[i][j] = verti[i-1][j] + grid[i][j];
            }
        }
        sum = 0;
        for(int j=0; j<m; j++) {
            sum += verti[n-1][j];
            cout << sum << " " << total/2.0 << endl;
            if(sum == total - sum) return true;
        }

        return false;
    }
};