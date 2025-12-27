class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos = -1;
        for(int i=n-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                pos = i-1;
                break;
            }
        }
        if(pos == -1) sort(nums.begin(), nums.end());
        else {
            for(int i=n-1; i>pos; i--){
                if(nums[i] > nums[pos]) {
                    swap(nums[i], nums[pos]);
                    break;
                }
            }
            sort(nums.begin()+pos+1, nums.end());
        }
    }
};