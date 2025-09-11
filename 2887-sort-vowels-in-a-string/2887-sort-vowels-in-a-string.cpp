class Solution {
public:
    string sortVowels(string s) {
        string vowels = "AEIOUaeiou";
        int n = s.size();
        string v1 = "", t=s;
        for(int i=0; i<n; i++){
            if(vowels.find(s[i]) != string::npos){
                v1 += s[i];
            }
        }
        sort(v1.begin(), v1.end());
        int j=0;
        for(int i=0; i<n; i++){
            if(vowels.find(t[i]) != string::npos){
                t[i] = v1[j];
                j++;
            }
        }
        return t;
    }
};