class Solution {
public:
    int greater(vector<int> &nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        int l=0, r=0;
        int ans = 0;
        while(r < n) {
            mp[nums[r]]++;
            while(l<n && mp.size() > k) {
                ans += n-r;
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return greater(nums, k-1) - greater(nums, k);
    }
};