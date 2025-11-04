class Solution {
public:
    vector<int> ans;
    void xSum(vector<int>&sub, int x){
        map<int, int> mp;
        for(int i=0; i<sub.size(); i++){
            mp[sub[i]]++;
        }
        vector<pair<int,int>> vec;
        for(auto it:mp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(), vec.end(), greater<pair<int,int>>());
        int sum = 0;
        for(int i=0; i<x && i<vec.size(); i++){
            sum += vec[i].first*vec[i].second;
        }
        ans.push_back(sum);
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> sub;
        for(int i=0; i<k; i++){
            sub.push_back(nums[i]);
        }
        xSum(sub, x);
        for(int i=k; i<nums.size(); i++){
            sub.erase(sub.begin());
            sub.push_back(nums[i]);
            xSum(sub, x);
        }
        return ans;
    }
};