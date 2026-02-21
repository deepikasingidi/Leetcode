class Solution {
public:
    bool is_prime(int n) {
        if(n <= 1) return false;
        for(int i=2; i*i <= n; i++) {
            if(n%i == 0) {
                return false;
            }
        }
        return true;
    }
    int setBits(int n) {
        int bits = 0;
        while(n > 0) {
            if(n&1) bits++;
            n = n >> 1;
        }
        return bits;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i=left; i<=right; i++) {
            if(is_prime(setBits(i))) cnt++;
        }
        return cnt;
    }
};