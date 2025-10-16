class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int x = abs(nums[i]%value);
            if(nums[i] < 0 && x!=0) mp[value-(abs(nums[i])%value)]++;
            else mp[nums[i]%value]++;
        }
        for(int i=0; i<value; i++){
            if(mp[i] == 0) return i;
        }
        int val = 0;
        int mini = INT_MAX;
        for(auto it : mp){
            cout << it.first << " " << it.second << endl;
            if(it.second < mini) {
                mini = it.second;
                val = it.first; 
            }
        }
        int ans = val + value*(mini-1) +value;
        return ans;
    }
};