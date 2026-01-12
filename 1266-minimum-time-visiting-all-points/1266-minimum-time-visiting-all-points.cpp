class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i=1; i<n; i++){
            int diff1 = abs(points[i][0]-points[i-1][0]);
            int diff2 = abs(points[i][1]-points[i-1][1]);

            int mini = min(diff1, diff2);
            int val = max(diff1-mini, diff2-mini);

            ans += mini + val;
        }
        return ans;
    }
};