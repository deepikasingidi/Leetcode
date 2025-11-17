class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1, curr = 0;
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            if(prev == -1 && nums[i] == 1) {
                prev = i;
            }
            else if(nums[i] == 1) {
                curr = i;
                ans = min(ans, curr-prev-1);
                prev = i;
            }
        }
        if(ans >= k) return true;
        return false;
    }
};