class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[flowers[i][0]]++;
            mp[flowers[i][1]+1]--;
        }
        vector<pair<int,int>> pr;
        for(auto it : mp) {
            pr.push_back({it.first, it.second});
        }
        for(int i=1; i<pr.size(); i++) {
            pr[i].second = pr[i].second + pr[i-1].second;
            cout << pr[i].first << " " << pr[i].second << endl;
        }
        vector<int> ans;
        for(int i=0; i<people.size(); i++) {
            int up = upper_bound(pr.begin(), pr.end(), make_pair(people[i], INT_MAX)) - pr.begin();
            if(up == 0) ans.push_back(0);
            else ans.push_back(pr[up-1].second);
        }
        return ans;
    }
};