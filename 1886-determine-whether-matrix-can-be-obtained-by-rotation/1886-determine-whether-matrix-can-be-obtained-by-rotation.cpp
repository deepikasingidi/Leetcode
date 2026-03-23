class Solution {
public:
    bool fun(int n, vector<vector<int>>& mat, vector<vector<int>>& target, int cnt) {
        vector<vector<int>> vec(n, vector<int>(n));

        if(cnt>=4) return false;

        for(int i=0; i<n; i++) {
            int k = 0;
            for(int j=n-1; j>=0; j--) {
                vec[i][k] = mat[j][i];
                k++;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(vec[i][j] != target[i][j]) return fun(n, vec, target, cnt+1);
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] != target[i][j]) return fun(n, mat, target, 1);
            }
        }
        return true;
    }
};