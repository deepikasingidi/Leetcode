class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int Xor = 0;
        for(int i=0; i<n; i++){
            Xor ^= nums[i];
        }
        int pos=0;
        for(int i=0; i<32; i++) {
            if(Xor & 1<<i) {
                pos = i;
                break;
            }
        }
        int v1=0, v2=0;
        for(int i=0; i<n; i++) {
            if(nums[i] & 1<<pos) v1 ^= nums[i];
            else v2 ^= nums[i];
        }
        return {v1, v2};
    }
};