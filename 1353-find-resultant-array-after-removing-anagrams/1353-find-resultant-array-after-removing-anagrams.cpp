class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        res.push_back(words[0]);
        for(int i=1; i<n; i++){
            string t = words[i-1];
            string s = words[i];
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if(s != t) res.push_back(words[i]);
        }
        return res;
    }
};