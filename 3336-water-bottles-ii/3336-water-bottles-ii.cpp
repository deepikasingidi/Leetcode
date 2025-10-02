class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int temp = numBottles;
        int cnt = 0;
        while(temp-numExchange >= 0){
            temp = temp-numExchange+1;
            numExchange++;
            cnt++;
        }
        return numBottles+cnt;
    }
};