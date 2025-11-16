class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        long long cnt = 0;
        long long mod = 1e9+7;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0'){
                ans += ((cnt*(cnt+1))/2);
                ans %= mod;
                cnt = 0;
            }
            if(s[i] == '1') cnt++;
        }
        ans += ((cnt*(cnt+1))/2);
        return ans;
    }
};