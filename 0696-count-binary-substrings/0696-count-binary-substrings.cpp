class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int cnt=0, one=0, zero=0;

        if(s[0]=='0') zero++;
        else one++;

        for(int i=1; i<n; i++){
            if(s[i]=='1') {
                if(s[i-1]=='0') one = 1;
                else one++;
                if(zero >= one) cnt++;
            }
            else {
                if(s[i-1]=='1') zero = 1;
                else zero++;
                if(one >= zero) cnt++;
            }
        }
        return cnt;
    }
};