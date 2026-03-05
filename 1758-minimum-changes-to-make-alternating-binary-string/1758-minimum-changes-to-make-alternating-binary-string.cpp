class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int zero = 0, one = 0;
        for(int i=0; i<n; i++) {
            if(i%2 != s[i]-'0') zero++;
            else one++;
        }
        return min(zero, one);
    }
};