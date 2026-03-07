class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        bool one = false, zero = false;
        for(int i=0; i<n; i++) {
            if(s[i]=='1') one = true;
            if(s[i]=='0' && one) zero = true;
            if(s[i]=='1' && zero) return false;
        }
        return true;
    }
};