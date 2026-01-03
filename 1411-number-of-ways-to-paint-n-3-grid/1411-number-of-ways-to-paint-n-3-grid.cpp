class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9+7;
        long long same = 6, diff = 6;
        for(int i=2; i<=n; i++){
            long long newSame = (3*same + 2*diff) % mod;
            long long newDiff = (2*same + 2*diff) % mod;
            same = newSame;
            diff = newDiff;
        }
        return (int)((same + diff) % mod);
    }
};