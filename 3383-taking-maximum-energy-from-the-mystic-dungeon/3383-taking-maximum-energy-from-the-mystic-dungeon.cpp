class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        map<int, int> mp;
        int n = energy.size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            if(mp[i%k] < 0) mp[i%k] = 0;
            mp[i%k] = mp[i%k]+energy[i];
        }
        for(auto it : mp){
            ans = max(ans, it.second);
        }
        return ans;
    }
};