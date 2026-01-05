class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long ans = 0;
        long long mini = abs(matrix[0][0]);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++){
                mini = min(mini, 1LL*abs(matrix[i][j]));
                ans += abs(matrix[i][j]);
                if(matrix[i][j] < 0) cnt++;
            }
        }
        if(cnt%2 == 0 || cnt == 0) return ans;
        else return ans - 2*mini;
        return 0;
    }
};