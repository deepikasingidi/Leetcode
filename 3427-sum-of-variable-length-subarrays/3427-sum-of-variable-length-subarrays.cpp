class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            prefix[i] = sum;
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            int ind = max(0, i-nums[i]);
            if(ind == 0) {
                ans += prefix[i];
            }
            else {
                ans += prefix[i]-prefix[ind-1];
            }
        }
        return ans;
    }
};