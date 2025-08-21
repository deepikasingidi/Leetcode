class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix;
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            prefix.push_back(mp.size());
        }
        vector<int> suffix(n);
        suffix[n-1] = 0;
        map<int, int> mp1;
        for(int i=n-1; i>0; i--){
            mp1[nums[i]]++;
            suffix[i-1] = mp1.size();
        }

        vector<int> res(n);
        for(int i=0; i<n; i++){
            res[i] = prefix[i] - suffix[i];
        }
        return res;
    }
};