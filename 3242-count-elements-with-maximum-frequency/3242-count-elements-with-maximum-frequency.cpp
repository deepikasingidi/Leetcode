class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        int maxi = INT_MIN;
        for(auto i : mp){
            maxi =  max(maxi, i.second);
        }
        int cnt = 0;
        for(auto i : mp){
            if(i.second == maxi) cnt+=i.second;
        }
        return cnt;
    }
};