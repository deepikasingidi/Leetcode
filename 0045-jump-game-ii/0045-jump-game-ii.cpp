class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0, maxi=0, curr = 0;
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            maxi = max(maxi, i+nums[i]);
            if(i == curr) {
                ans++;
                curr = maxi;
            }
        }
        return ans;
    }
};