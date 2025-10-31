class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        map<int, int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        for(auto it:mp){
            if(it.second > 1) res.push_back(it.first);
        }
        return res;
    }
};