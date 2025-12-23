class Solution {
public: 
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [] (const vector<int>&a, const vector<int>&b) {
            return a[1] < b[1];
        });
        vector<int> profit;
        int maxi = 0;
        for(int i=0; i<n; i++) {
            maxi = max(maxi, events[i][2]);
            profit.push_back(maxi);
        }
        int ans = maxi;
        for(int i=0; i<n; i++){
            int start = events[i][0];
            int low = 0;
            int high = n-1;
            int ind = -1;
            while(low <= high) {
                int mid = low + (high-low)/2;
                if(events[mid][1] < start){
                    low = mid+1;
                    ind = mid;
                }
                else high = mid-1;
            }
            // cout << start << "->" << ind << endl;
            if(ind != -1) ans = max(ans, events[i][2]+profit[ind]);
        }
        return ans;
    }
};