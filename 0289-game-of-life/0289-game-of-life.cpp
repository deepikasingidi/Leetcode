class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> res(n, vector<int>(m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int cnt = 0;
                if(i-1>=0 && j-1>=0 && board[i-1][j-1]==1) cnt++;
                if(i-1>=0 && board[i-1][j] == 1) cnt++;
                if(i-1>=0 && j+1<m && board[i-1][j+1]==1) cnt++;
                if(j-1>=0 && board[i][j-1]==1) cnt++;
                if(j+1<m && board[i][j+1]==1) cnt++;
                if(i+1<n && j-1>=0 && board[i+1][j-1]==1) cnt++;
                if(i+1<n && board[i+1][j]==1) cnt++;
                if(i+1<n && j+1<m && board[i+1][j+1]==1) cnt++;

                if(board[i][j] == 1) {
                    if(cnt < 2) res[i][j] = 0;
                    else if(cnt == 2 || cnt == 3) res[i][j] = 1;
                    else if(cnt > 3) res[i][j] = 0;
                }
                else {
                    if(cnt == 3) res[i][j] = 1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                board[i][j] = res[i][j];
            }
        }
    }
};