class Solution {
public:
    vector<vector<int>> dp;
    int fun(vector<int>&arr, int n, int i, int prev) {
        if(i == n) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int pick = 0;
        if(prev==-1 || arr[i]>arr[prev]) pick = 1 + fun(arr, n, i+1, i);
        int non_pick = fun(arr, n, i+1, prev);

        dp[i][prev+1] = max(pick, non_pick);

        return dp[i][prev+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(n+1, -1));
        int cnt = fun(nums, n, 0, -1);
        
        return dp[0][0];
    }
};