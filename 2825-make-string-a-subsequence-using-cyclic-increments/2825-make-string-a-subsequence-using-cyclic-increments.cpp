class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int idx = 0;
        char curr = str2[idx];
        char prev;

        if(curr == 'a') prev = 'z';
        else prev = curr-1;

        for(int i=0; i<str1.size(); i++) {
            if(str1[i]==curr || str1[i]==prev) {
                idx++;
                if(idx == str2.size()) return true;
                curr = str2[idx];

                if(curr == 'a') prev = 'z';
                else prev = curr-1;
            }
        }
        return false;
    }
};