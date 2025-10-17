class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char, int> mp;
        int ans = 0;
        int l=0, r=0;
        while(r<n){
            mp[s[r]]++;
            while((mp[s[l]] > 1 || mp[s[r]] > 1) && l<n){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                int s = mp.size();
                ans = max(ans, s);
                l++;
            }
            int s = mp.size();
            ans = max(ans, s);
            r++;
        }
        return ans;
    }
};