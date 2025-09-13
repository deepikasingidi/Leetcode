class Solution {
public:
    int maxFreqSum(string s) {
        string vowels = "AEIOUaeiou";
        map<char, int> vow;
        map<char, int> con;
        for(int i=0; i<s.size(); i++){
            if(vowels.find(s[i]) != string::npos) con[s[i]]++;
            else vow[s[i]]++;
        }
        int fre1=0, fre2=0;
        for(auto it : vow){
            fre1 = max(fre1, it.second);
        }
        for(auto it : con){
            fre2 = max(fre2, it.second);
        }
        return fre1 + fre2;
    }
};