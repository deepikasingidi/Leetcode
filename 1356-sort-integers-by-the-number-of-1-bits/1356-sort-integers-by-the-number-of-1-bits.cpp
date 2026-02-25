class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a,int b) {
            int cnt1 = __builtin_popcount(a), cnt2 = __builtin_popcount(b);
            if(cnt1 == cnt2) return a<b;
            return  cnt1 < cnt2;
        });
        return arr;
    }
};