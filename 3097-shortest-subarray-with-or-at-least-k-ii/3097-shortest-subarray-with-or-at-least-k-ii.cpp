class Solution {
public:
    int convert(vector<int>&bits) {
        int num=0;
        for(int i=0; i<32; i++){
            if(bits[i] > 0) {
                num += (1<<i);
            }
        }
        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k==0) return 1;
        vector<int> bits(32, 0);
        int l=0, r=0, n=nums.size();
        int num = 0, ans = INT_MAX;
        while(r<n) {
            for(int i=0; i<32; i++){
                if(nums[r] & (1<<i)) {
                    bits[i]++;
                }
            }
            num = convert(bits);
            while(l<=r && num>=k) {
                ans = min(ans, r-l+1);
                for(int i=0; i<32; i++) {
                    if(nums[l] & (1<<i)) {
                        bits[i]--;
                    }
                }
                num = convert(bits);
                l++;
            }
            if(num>=k) ans = min(ans, r-l+1);
            r++;
        }
        return ans==INT_MAX? -1 : ans;
    }
};