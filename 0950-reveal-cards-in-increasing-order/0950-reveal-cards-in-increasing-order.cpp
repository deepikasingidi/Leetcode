class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end(), greater<int>());
        vector<int> res;
        res.push_back(deck[0]);
        for(int i=1; i<n; i++){
            int val = res[res.size()-1];
            res.erase(res.end());
            res.insert(res.begin(), val);
            res.insert(res.begin(), deck[i]);
        }
        return res;
    }
};