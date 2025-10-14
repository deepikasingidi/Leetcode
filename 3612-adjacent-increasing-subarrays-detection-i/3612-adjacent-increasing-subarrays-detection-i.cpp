class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2*k) return false;
        for(int i=0; i<=n-(2*k); i++){
            bool f=true;
            for(int j=i; j<i+k-1; j++){
                if(nums[j]>=nums[j+1]){
                    f=false;
                    break;
                }
            }
            if(f){
                for(int x=i+k; x<i+k+k-1; x++){
                    if(nums[x]>=nums[x+1]){
                        f=false;
                        break;
                    }
                }
                if(f) return f;
            }
        }
        return false;
    }
};