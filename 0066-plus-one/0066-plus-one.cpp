class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        int val = digits[n-1] + 1;
        ans.push_back(val%10);
        int carry = val/10;
        for(int i=n-2; i>=0; i--) {
            int val = digits[i] + carry;
            ans.push_back(val%10);
            carry = val/10;
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};