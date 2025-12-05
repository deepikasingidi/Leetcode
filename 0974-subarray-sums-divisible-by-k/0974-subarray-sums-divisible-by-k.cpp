class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        mp[0] = 1;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            int mod = (sum%k + k) % k;
            if(mp[mod] != 0) ans += mp[mod];
            mp[mod]++;
        }
        return ans;
    }
};