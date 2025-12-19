class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<m; i++) {
            if(board[0][i] == 'O') q.push({0,i});
            if(board[n-1][i] == 'O') q.push({n-1,i});
        }

        for(int i=0; i<n; i++) {
            if(board[i][0] == 'O') q.push({i,0});
            if(board[i][m-1] == 'O') q.push({i,m-1});
        }

        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            int i = top.first;
            int j = top.second;

            board[i][j] = 'P';
            if(i-1 >= 0 && board[i-1][j] == 'O') q.push({i-1,j});
            if(i+1 < n && board[i+1][j] == 'O') q.push({i+1, j});
            if(j-1 >= 0 && board[i][j-1] == 'O') q.push({i, j-1});
            if(j+1 < m && board[i][j+1] == 'O') q.push({i,j+1});
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'P') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};