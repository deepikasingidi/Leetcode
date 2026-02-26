class Solution {
public:
    void addOne(string &s) {
        int carry = 0;
        int n = s.size();
        if(s[n-1] == '1') {
            s[n-1] = '0';
            carry = 1;
        }
        else if(s[n-1] == '0') s[n-1] = '1';
        for(int i=s.size()-2; i>=0; i--) {
            if(carry && s[i]=='1') {
                s[i] = '0';
                carry = 1;
            }
            else if(carry && s[i]=='0') {
                s[i] = '1';
                carry = 0;
            }
        }
        if(carry) s.insert(s.begin(), '1');
    }
    int numSteps(string s) {
        int n = s.size();
        int ans = 0;
        while(n > 1) {
            if(s[n-1] == '1'){
                addOne(s);
            }
            else if(s[n-1] == '0') s.pop_back();
            n = s.size();
            ans++;
        }
        return ans;
    }
};