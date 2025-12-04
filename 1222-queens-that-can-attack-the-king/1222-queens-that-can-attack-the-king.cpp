class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;

        vector<vector<int>> chess(8, vector<int>(8,0));

        for(int i=0; i<queens.size(); i++) {
            chess[queens[i][0]][queens[i][1]] = 1;
        }

        int i1 = king[0]-1, j1 = king[1]-1;
        while(i1>=0 && j1>=0) {
            if(chess[i1][j1] == 1) {
                res.push_back({i1,j1});
                break;
            }
            i1--;
            j1--;
        }

        i1 = king[0]-1, j1 = king[1];
        while(i1>=0) {
            if(chess[i1][j1] == 1) {
                res.push_back({i1,j1});
                break;
            }
            i1--;
        }

        i1 = king[0]-1, j1 = king[1]+1;
        while(i1>=0 && j1<8) {
            if(chess[i1][j1] == 1) {
                res.push_back({i1,j1});
                break;
            }
            i1--;
            j1++;
        }

        i1 = king[0], j1 = king[1]-1;
        while(j1>=0) {
            if(chess[i1][j1] == 1) {
                res.push_back({i1,j1});
                break;
            }
            j1--;
        }

        i1 = king[0], j1 = king[1]+1;
        while(j1<8) {
            if(chess[i1][j1] == 1) {
                res.push_back({i1,j1});
                break;
            }
            j1++;
        }

        i1 = king[0]+1, j1 = king[1]-1;
        while(i1<8 && j1>=0) {
            if(chess[i1][j1] == 1) {
                res.push_back({i1,j1});
                break;
            }
            i1++;
            j1--;
        }

        i1 = king[0]+1, j1 = king[1];
        while(i1<8) {
            if(chess[i1][j1] == 1) {
                res.push_back({i1,j1});
                break;
            }
            i1++;
        }

        i1 = king[0]+1, j1 = king[1]+1;
        while(i1<8 && j1<8) {
            if(chess[i1][j1] == 1) {
                res.push_back({i1,j1});
                break;
            }
            i1++;
            j1++;
        }
        return res;
    }
};