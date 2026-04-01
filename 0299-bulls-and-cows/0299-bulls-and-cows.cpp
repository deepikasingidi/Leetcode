class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> mp;
        int n = secret.size();
        int a=0, b=0;
        for(int i=0; i<n; i++){
            if(secret[i] == guess[i]) a++;
            else mp[secret[i]]++;
        }
        for(int i=0; i<n; i++) {
            if(secret[i]!=guess[i] && mp.find(guess[i]) != mp.end()){
                mp[guess[i]]--;
                if(mp[guess[i]] == 0) mp.erase(guess[i]);
                b++;
            }
        }
        string res = "";
        res += to_string(a);
        res += 'A';
        res += to_string(b);
        res += 'B';
        return res;
    }
};