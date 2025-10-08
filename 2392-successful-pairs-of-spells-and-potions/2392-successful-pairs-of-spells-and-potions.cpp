class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            long long rem = ceil((double)success/spells[i]);
            int lb = lower_bound(potions.begin(), potions.end(), rem)-potions.begin();
            long long val = potions.size()-lb;
            ans.push_back(val);
        }
        return ans;
    }
};