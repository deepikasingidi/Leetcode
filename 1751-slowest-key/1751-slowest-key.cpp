class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxi = releaseTimes[0];
        for(int i=1; i<releaseTimes.size(); i++){
            maxi = max(maxi, releaseTimes[i]-releaseTimes[i-1]);
        }
        char ans = '\0';
        if(releaseTimes[0] == maxi) ans = keysPressed[0];
        for(int i=1; i<releaseTimes.size(); i++){
            if(releaseTimes[i]-releaseTimes[i-1] == maxi){
                ans = max(ans, keysPressed[i]);
            }
        }
        return ans;
    }
};