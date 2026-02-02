class Solution {
public:
    int fun(vector<int>& nums, int val) {
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
                res += nums[i]/val;
                if(nums[i]%val != 0) res++;
        }
        return res;
    }
    int minimumK(vector<int>& nums) {
        int low = 1, high = 100000;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int num = fun(nums, mid);
            if(num <= 1ll*mid*mid) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};