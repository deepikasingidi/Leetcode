class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();
        map<string, int> mp;
        for(int i=0; i<n; i++) {
            if(words[i].size() >= k) {
                string sub = words[i].substr(0, k);
                mp[sub]++;
            }
        }
        int ans = 0;
        for(auto it : mp) {
            if(it.second > 1) ans++;
        }
        return ans;
    }
};