class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0;
        int p = 0;
        if(n==0) return 1;
        while(n > 0) {
            int rem = n%2;
            if(rem == 0) {
                ans += pow(2,p);
            }
            n /= 2;
            p++;
        }
        return ans;
    }
};