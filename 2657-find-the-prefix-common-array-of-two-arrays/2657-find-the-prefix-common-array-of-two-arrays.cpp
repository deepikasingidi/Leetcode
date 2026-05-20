class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int, int> mp;
        vector<int> C;
        int n = A.size();
        for(int i=0; i<n; i++) {
            mp[A[i]]++;
            int cnt = 0;
            for(int j=0; j<=i; j++){
                if(mp.find(B[j]) != mp.end()) cnt++;
            }
            C.push_back(cnt);
        }
        return C;
    }
};