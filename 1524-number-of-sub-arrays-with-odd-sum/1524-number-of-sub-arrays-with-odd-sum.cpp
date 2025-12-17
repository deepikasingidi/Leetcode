class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long even = 0, odd = 0;
        int n = arr.size();
        int ans = 0;
        long long sum = 0;
        int mod = 1e9+7;
        for(int i=0; i<n; i++) {
            sum += arr[i];
            if(sum%2 == 1) {
                ans = ans%mod + 1 + even%mod;
                odd++;
            }
            else {
                ans = ans%mod + odd%mod;
                even++;
            }
        }
        return ans;
    }
};