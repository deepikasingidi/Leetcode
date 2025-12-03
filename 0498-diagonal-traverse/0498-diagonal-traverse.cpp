class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> ans;

        pair<int, int> top(0,0);
        pair<int, int> left(0,0);
        
        bool flage = true;
        while(top.first<n && top.second<m && left.first<n && left.second<m) {
            if(flage) {
                int i = left.first, j = left.second;
                while(i >= top.first && j <= top.second) {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            }
            else {
                int i = top.first, j = top.second;
                while(i <= left.first && j>= left.second) {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }

            if(top.second == m-1) top.first++;
            else top.second++;

            if(left.first == n-1) left.second++;
            else left.first++;

            if(top.first==n && top.second==m && left.first==n && left.second==m) break;
            flage = !flage;
        }
        return ans;
    }
};