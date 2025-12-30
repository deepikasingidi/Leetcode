class Solution {
public:
    int count(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0, r=0;
        int cnt = 0, ans = 0;
        while(r<n){
            if(nums[r]%2) cnt++;
            while(cnt > k && l<n) {
                ans += n-r;
                if(nums[l]%2) cnt--;
                l++;
            }
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums, k-1) - count(nums, k);
    }
};