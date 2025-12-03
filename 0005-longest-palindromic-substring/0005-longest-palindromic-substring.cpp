class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> vec(n, vector<bool>(n,false));
        string ans;
        for(int i=0; i<n; i++) {
            vec[i][i] = true;
            ans = s.substr(i,1);
        }
        n--;
        for(int i=0; i<n; i++) {
            if(s[i] == s[i+1]){
                vec[i][i+1] = true; 
                ans = s.substr(i, 2);
            }
        }
        int j=2;
        while(n--) {
            for(int i=0; i<n; i++) {
                if(s[i] == s[i+j] && vec[i+1][i+j-1] == true){
                    vec[i][i+j] = true;
                    ans = s.substr(i, j+1);
                }
            }
            j++;
        }

        // for(int i=0; i<vec.size(); i++){
        //     for(int j=0; j<vec.size(); j++){
        //         cout << vec[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};