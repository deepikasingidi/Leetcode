class Solution {
public:
    int minOperations(string s) {
        string t = s;
        sort(t.begin(), t.end());
        if(s == t) return 0;
        int ans = INT_MAX;
        
        string temp1 = s;
        sort(temp1.begin(), temp1.end()-1);
        if(temp1 == t) ans = min(ans, 1);
        sort(temp1.begin()+1, temp1.end());
        if(temp1 == t) ans = min(ans , 2);
        sort(temp1.begin(), temp1.end()-1);
        if(temp1 == t) ans = min(ans, 3);

        string temp2 = s;
        sort(temp2.begin()+1, temp2.end());
        if(temp2 == t) ans = min(ans, 1);
        sort(temp2.begin(), temp2.end()-1);
        if(temp2 == t) ans = min(ans, 2);
        sort(temp2.begin()+1, temp2.end());
        if(temp2 == t) ans = min(ans, 3);

        return (ans == INT_MAX) ? -1 : ans;
    }
};