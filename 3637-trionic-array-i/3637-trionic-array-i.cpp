class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        bool inc1 = false, dec = false, inc2 = false;
        for(int i=1; i<n; i++) {
            if(nums[i]<nums[i-1] && inc1 && dec && inc2) return false;
            if(nums[i] > nums[i-1] && inc1==true && dec==true) {
                inc2 = true;
            }
            else if(nums[i] < nums[i-1] && inc1==true) {
                dec = true;
            }
            else if(nums[i] > nums[i-1]) inc1 = true;
            else return false;
        }
        return inc1&inc2&dec;
    }
};