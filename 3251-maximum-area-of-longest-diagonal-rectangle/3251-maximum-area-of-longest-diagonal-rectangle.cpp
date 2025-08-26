class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& mat) {
        int n = mat.size();
        int maxi = INT_MIN;
        double root;
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            root = (mat[i][0]*mat[i][0])+(mat[i][1]*mat[i][1]);
            if(root >= maxi) {
                maxi = root;
            }
        }
        for(int i=0; i<n; i++){
            int root1 = (mat[i][0]*mat[i][0]) + (mat[i][1]*mat[i][1]);
            if(root1 == maxi) ans = max(ans, mat[i][0]*mat[i][1]);
        }
        return ans;
    }
};