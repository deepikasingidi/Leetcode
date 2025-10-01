class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = 0;
        int temp = numBottles;
        while(temp/numExchange > 0){
            cnt += temp/numExchange;
            int rem = temp - ((temp/numExchange) * numExchange);
            temp = (temp/numExchange) + rem;
        }
        return numBottles+cnt;
    }
};