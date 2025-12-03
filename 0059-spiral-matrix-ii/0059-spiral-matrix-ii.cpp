class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n, vector<int>(n, 0));
        int top=0, down=n-1, left=0, right=n-1;
        int ele = 1;
        while(ele <= n*n) {
            for(int i=left; i<=right; i++){
                vec[top][i] = ele++;
            }
            top++;
            for(int i=top; i<=down; i++) {
                vec[i][right] = ele++;
            }
            right--;

            if(left>right || top>down) break;
            for(int i=right; i>=left; i--){
                vec[down][i] = ele++;
            }
            down--;

            for(int i=down; i>=top; i--) {
                vec[i][left] = ele++;
            }
            left++;
        }
        return vec;
    }
};