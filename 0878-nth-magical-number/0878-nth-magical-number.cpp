class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long mod = 1e9+7;
        long long low = min(a,b);
        long long high = n * 1ll * min(a,b);
        long long ans;
        while(low <= high) {
            long long mid = low+(high-low)/2;
            long long div_a = mid/a;
            long long div_b = mid/b;
            long long lcm = (a*b)/ __gcd(a,b);
            long long div_ab = mid/lcm;
            long long cnt = div_a + div_b - div_ab;
            if(cnt >= n) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans % mod;
    }
};