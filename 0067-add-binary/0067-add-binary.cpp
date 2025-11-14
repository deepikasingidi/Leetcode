class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ans  = "";
        int i=a.size()-1, j=b.size()-1;
        while(i>=0 && j>=0){
            int cnt = 0;
            if(a[i]=='1') cnt++;
            if(b[j]=='1') cnt++;
            if(carry == 1) cnt++;

            if(cnt == 3) {
                ans += "1";
                carry = 1;
            }
            else if(cnt == 2) {
                ans += "0";
                carry = 1;
            }
            else if(cnt == 1){
                ans += "1";
                carry = 0;
            }
            else if(cnt == 0) {
                ans += "0";
                carry = 0;
            }
            i--;
            j--;
        }

        while(i>=0) {
            int cnt1 = 0;
            if(carry == 1) cnt1++;
            if(a[i] == '1') cnt1++;

            if(cnt1 == 2) {
                ans += "0";
                carry = 1;
            }
            else if(cnt1 == 1) {
                ans += "1";
                carry = 0;
            }
            else if(cnt1 == 0) {
                ans += "0";
                carry = 0;
            }
            i--;
        }

        while(j>=0){
            int cnt2 = 0;
            if(carry == 1) cnt2++;
            if(b[j] == '1') cnt2++;

            if(cnt2 == 2) {
                ans += "0";
                carry = 1;
            }
            else if(cnt2 == 1) {
                ans += "1";
                carry = 0;
            }
            else if(cnt2 == 0) {
                ans += "0";
                carry = 0;
            }
            j--;
        }
        if(carry == 1) ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};