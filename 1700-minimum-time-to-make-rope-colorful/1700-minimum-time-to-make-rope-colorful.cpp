class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int sum = 0;
        int cnt = 0;
        int maxi = neededTime[0];
        int sum1 = neededTime[0];
        for(int i=1; i<n; i++){
            if(colors[i] == colors[i-1]){
                sum1 += neededTime[i];
                maxi = max(maxi, neededTime[i]);
            }
            else {
                sum += sum1-maxi;
                maxi = neededTime[i];
                sum1 = neededTime[i];
            }
        }
        sum += sum1-maxi;
        return sum;
    }
};