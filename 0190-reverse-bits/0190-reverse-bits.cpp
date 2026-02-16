class Solution {
public:
    int reverseBits(int n) {
        int i = 31;
        int res = 0;
        while(i>=0 && n>0) {
            if(n%2) {
                res += pow(2,i);
            }
            n /= 2;
            i--;
        }
        return res;
    }
};