class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;

        vector<vector<pair<int,int>>> vec;

        int n = heights.size();
        int m = heights[0].size();
        vec.resize(n, vector<pair<int,int>>(m, {0,0}));

        queue<pair<int, int>> paci;
        
        for(int i=0; i<n; i++) {
            vec[i][0].first = 1;
            paci.push({i,0});
        }
        for(int i=1; i<m; i++) {
            vec[0][i].first = 1;
            paci.push({0,i});
        }

        while(!paci.empty()) {
            int l = paci.front().first;
            int r = paci.front().second;
            int ele = heights[l][r];
            //[l-1][r] [l][r-1] [l+1][r] [l][r+1]
            if(l-1>=0 && vec[l-1][r].first!=1 && heights[l-1][r] >= ele) {
                vec[l-1][r].first = 1;
                paci.push({l-1,r});
            }

            if(r-1>=0 && vec[l][r-1].first!=1 && heights[l][r-1] >= ele) {
                vec[l][r-1].first = 1;
                paci.push({l,r-1});
            }

            if(l+1<n && vec[l+1][r].first!=1 && heights[l+1][r] >= ele) {
                vec[l+1][r].first = 1;
                paci.push({l+1,r});
            }

            if(r+1<m && vec[l][r+1].first!=1 && heights[l][r+1] >= ele) {
                vec[l][r+1].first = 1;
                paci.push({l,r+1});
            }
            paci.pop();
        }

        queue<pair<int, int>> atla;
        
        for(int i=0; i<m; i++) {
            vec[n-1][i].second = 1;
            atla.push({n-1,i});
        }
        for(int i=0; i<n-1; i++) {
            vec[i][m-1].second = 1;
            atla.push({i,m-1});
        }

        while(!atla.empty()) {
            int l = atla.front().first;
            int r = atla.front().second;
            int ele = heights[l][r];
            //[l-1][r] [l][r-1] [l+1][r] [l][r+1]
            if(l-1>=0 && vec[l-1][r].second!=1 && heights[l-1][r] >= ele) {
                vec[l-1][r].second = 1;
                atla.push({l-1,r});
            }

            if(r-1>=0 && vec[l][r-1].second!=1 && heights[l][r-1] >= ele) {
                vec[l][r-1].second = 1;
                atla.push({l,r-1});
            }

            if(l+1<n && vec[l+1][r].second!=1 && heights[l+1][r] >= ele) {
                vec[l+1][r].second = 1;
                atla.push({l+1,r});
            }

            if(r+1<m && vec[l][r+1].second!=1 && heights[l][r+1] >= ele) {
                vec[l][r+1].second = 1;
                atla.push({l,r+1});
            }
            atla.pop();
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vec[i][j].first == 1 && vec[i][j].second == 1){
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    res.push_back(v);
                }
            }
        }

        return res;
    }
};