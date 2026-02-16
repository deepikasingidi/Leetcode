class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        map<int, int> mp1;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto it : mp) {
            mp1[it.second]++;
        }
        for(int i=0; i<n; i++) {
            if(mp1[mp[nums[i]]] == 1) return nums[i];
        }
        return -1;
    }
};