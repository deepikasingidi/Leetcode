class Solution {
public:
    int smallestNumber(int n) {
        int num = 1;
        int x = 1;
        while(num <= 1023) {
            if(num >= n) return num;
            num = pow(2,x)-1;
            x++;
        }
        return 0;
    }
};