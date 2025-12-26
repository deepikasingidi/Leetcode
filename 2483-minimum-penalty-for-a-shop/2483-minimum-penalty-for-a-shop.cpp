class Solution {
public:
    int bestClosingTime(string customers) {
        int y = 0;
        int n = customers.size();
        for(int i=0; i<n; i++){
            if(customers[i] == 'Y') y++;
        }
        int mini = INT_MAX;
        int x = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(x+y < mini) {
                mini = x+y;
                ans = i;
            }

            if(customers[i] == 'N') x++;
            else y--;
        }
        if(x+y < mini) {
            ans = n;
        }
        return ans;
    }
};