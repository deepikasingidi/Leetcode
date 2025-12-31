class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = nums[0];
        for(int i=1; i<n; i++) {
            maxi = max(maxi, nums[i]);
        }

        int l=0, r=0;
        long long cnt = 0;
        long long ans = 0;
        while(r<n) {
            if(nums[r] == maxi) cnt++;
            while(l<n && cnt >= k) {
                ans += n-r;
                if(nums[l] == maxi) cnt--;
                l++;
            }
            r++;
        }
        return ans;
    }
};