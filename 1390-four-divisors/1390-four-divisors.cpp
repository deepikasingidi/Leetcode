class Solution {
public:
    int fun(int num) {
        int cnt = 0;
        vector<int> vec;
        for(int i=2; i<=num/2; i++){
            if(num%i == 0) {
                vec.push_back(i);
            }
            if(vec.size() > 2) return 0;
        }
        int sum = 0;
        if(vec.size() == 2) {
            sum = 1 + num + vec[0] + vec[1];
        }
        return sum;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += fun(nums[i]);
        }
        return ans;
    }
};