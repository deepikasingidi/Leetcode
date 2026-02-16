class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string res = "";
        for(int i=0; i<n; i++) {
            int score = 0;
            for(auto ch : words[i]) {
                score += weights[ch-'a'];
            }
            int val = 25-(score%26);
            res += 'a'+val;
        }
        return res;
    }
};