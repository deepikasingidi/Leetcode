class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string t = "";
            for(int i=1; i<s.size(); i++){
                t += to_string(((s[i-1]-'0')+(s[i]-'0'))%10);
            }
            cout << t << " ";
            s = t;
        }
        if(s[0]==s[1]) return true;
        return false;
    }
};