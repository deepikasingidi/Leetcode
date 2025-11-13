class Solution {
public:
    int maxOperations(string s) {
        int  cnt = 0;
        int ans = 0;
        if(s[s.size()-1] == '0') cnt++;
        for(int i=s.size()-2; i>=0; i--){
            if(s[i]=='0' && s[i+1]=='1') cnt++;
            if(s[i]=='1') ans += cnt;
            cout << ans << endl;
        }
        return ans;
    }
};