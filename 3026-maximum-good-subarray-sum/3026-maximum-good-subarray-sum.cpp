class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> mp;
        int n = nums.size();
        vector<long long> pre(n+1);
        long long sum = 0;
        long long ans = -1e18;
        pre[0] = 0;
        for(long long i=0; i<n; i++) {
            sum += 1ll*nums[i];
            pre[i+1] = sum;

            if(mp.find(nums[i]-k) != mp.end()){
                long long ind = mp[nums[i]-k];
                ans = max(ans, pre[i+1]-pre[ind-1]);
            }
            if(mp.find(nums[i]+k) != mp.end()) {
                long long ind = mp[nums[i]+k];
                ans = max(ans, pre[i+1]-pre[ind-1]);
            }

           if (mp.find(nums[i]) == mp.end()) {
            mp[nums[i]] = i + 1;
}
            else {
                long long val = pre[i]-pre[mp[nums[i]]-1];
                if(val <= 0) mp[1ll*nums[i]] = i+1;
            }

        }
        if(ans == -1e18) return 0;
        return ans;
    }
};