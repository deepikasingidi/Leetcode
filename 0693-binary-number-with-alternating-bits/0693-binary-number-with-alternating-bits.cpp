class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n%2;
        n /= 2;
        while(n > 0) {
            int curr = n%2;
            if(curr == prev) return false;
            n /= 2;
            prev = curr;
        }
        return true;
    }
};