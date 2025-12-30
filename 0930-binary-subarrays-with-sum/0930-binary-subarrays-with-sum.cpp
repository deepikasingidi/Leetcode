class Solution {
public:
    int greater(vector<int> &nums, int k) {
        int n = nums.size();
        int l=0, r=0;
        int sum = 0, ans = 0;
        while(r<n){
            sum += nums[r];
            while(sum > k && l<n) {
                ans += n-r;
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans;
    }
    int lesser(vector<int> &nums, int k) {
        if(k==0) return 0;
        int n = nums.size();
        int l=0, r=0;
        int sum =0, ans = 0;
        while(r<n) {
            sum += nums[r];
            while(l<r && sum>=k) {
                sum -= nums[l];
                l++;
            }
            if(sum < k) ans += r-l+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int total = n*(n+1)/2;
        int cnt1 = greater(nums, goal);
        int cnt2 = lesser(nums, goal);
        cout << cnt1 << " " << cnt2;
        return total - cnt1 - cnt2;
    }
};