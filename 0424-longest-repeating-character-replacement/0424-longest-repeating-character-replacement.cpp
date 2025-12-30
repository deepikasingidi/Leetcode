class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l=0, r=0;
        int n = s.size();
        int maxi = 0;
        int ans = 0;
        while(r < n) {
            mp[s[r]]++;
            for(auto it:mp){
                maxi = max(maxi, it.second);
            }

            while((r-l+1)-maxi > k && l<n) {
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                for(auto it:mp) {
                    maxi = max(maxi, it.second);
                }
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};