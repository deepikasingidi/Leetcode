class Solution {
public:
    int fun(string &answerKey, int k, char ch) {
        int n = answerKey.size();
        int l=0, r=0;
        int cnt = 0, ans = 0;
        while(r < n) {
            if(answerKey[r] == ch) cnt++;
            while(l < n && cnt>k){
                if(answerKey[l] == ch) cnt--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    } 
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t = fun(answerKey, k, 'T');
        int f = fun(answerKey, k, 'F');

        return max(t, f);
    }
};