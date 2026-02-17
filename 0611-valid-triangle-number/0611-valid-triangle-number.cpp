class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) continue;
            for(int j=i+1; j<n-1; j++) {
                int sum = nums[i]+nums[j];
                int lb = lower_bound(nums.begin(), nums.end(), sum) - nums.begin();
                ans +=  (lb-j-1);
            }
        }
        return ans;
    }
};