class Solution {
public:
    long long flowerGame(int n, int m) {
        long long cnt = 0;
        long long ev1, ev2, od1, od2;
        ev1 = n/2;
        ev2 = m/2;
        od1 = ev1;
        od2 = ev2;
        if(n%2 == 1) od1++;
        if(m%2 == 1) od2++;
        cnt = (ev1*od2)+(ev2*od1);
        return cnt;
    }
};