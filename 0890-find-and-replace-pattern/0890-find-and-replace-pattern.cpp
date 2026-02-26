class Solution {
public:
    bool fun(string s1, string s2) {
        map<char, char> mp;
        int n=s1.size();
        for(int i=0; i<n; i++) {
            if(mp.find(s1[i])!=mp.end()) {
                if(mp[s1[i]]==s2[i]) continue;
                if(mp[s1[i]]!=s2[i]) return false;
            }
            mp[s1[i]] = s2[i];
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int n = words.size();
        for(int i=0; i<n; i++) {
            if(fun(pattern, words[i]) && fun(words[i], pattern)) res.push_back(words[i]);
        }
        return res;
    }
};