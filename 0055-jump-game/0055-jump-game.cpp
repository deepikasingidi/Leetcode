class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i,n = nums.size();
        int maxi = 0;
        for(i=0;i<=maxi && i<n; i++){
            maxi = max(maxi,i+nums[i]);
            if(maxi>=n-1) return true;
        }
        return false;
    }
};