class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            map<char, int> mp;
            set<int> st;
            int x;
            for(int j=i; j<n; j++){
                mp[s[j]]++;
                int val = mp[s[j]];
                bool flag = true;
                for(auto it : mp){
                    if(it.second != val){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    x = j-i+1;
                }
            }
            ans = max(ans, x);
            mp.clear();
        }
        return ans;
    }
};