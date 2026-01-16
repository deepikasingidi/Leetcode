class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            map<int, int> mp;
            int sum = 0;
            for(int j=i; j<n; j++) {
                sum += nums[j];
                mp[nums[j]]++;
                if(mp.find(sum) != mp.end()) cnt++;
            }
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
        }
        return cnt;
    }
};