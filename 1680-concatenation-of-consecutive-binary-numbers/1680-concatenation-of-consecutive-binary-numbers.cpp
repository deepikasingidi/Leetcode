class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9+7;
        long long res = 0;
        for(int i=1; i<=n; i++) {
            int size = log2(i)+1;
            res = ((res << size) | i)%mod;
        }
        return res%mod;
    }
};