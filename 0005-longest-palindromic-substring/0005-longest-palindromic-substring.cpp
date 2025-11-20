class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++){
            string sub = "";
            for(int j=i; j<s.size(); j++){
                sub += s[j];
                int l=0, r=sub.size()-1;
                bool flag = true;
                while(r >= l) {
                    if(sub[l] != sub[r]) {
                        flag = false;
                        break;
                    }
                    l++;
                    r--;
                }
                if(flag && sub.size() > ans.size()) ans = sub;
                if(ans.size() >= s.size()-i) break;
            }
        }
        return ans;
    }
};