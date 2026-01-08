class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        long long n = energyDrinkA.size();
        vector<vector<long long>> dp(2, vector<long long>(n,0));
        for(int i=0; i<n; i++) {
            if(i==0) {
                dp[0][i] = energyDrinkA[0];
                dp[1][i] = energyDrinkB[0];
            }
            else if(i == 1) {
                dp[0][i] = dp[0][i-1] + energyDrinkA[1];
                dp[1][i] = dp[1][i-1] + energyDrinkB[1];
            }
            else {
                dp[0][i] = max(dp[0][i-1], dp[1][i-2]) + energyDrinkA[i];
                dp[1][i] = max(dp[1][i-1], dp[0][i-2]) + energyDrinkB[i];
            }
        }
        return max(dp[0][n-1], dp[1][n-1]);
    }
};