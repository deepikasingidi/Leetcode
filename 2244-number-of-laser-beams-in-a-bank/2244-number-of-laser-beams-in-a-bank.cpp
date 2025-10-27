class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> vec;
        for(int i=0; i<bank.size(); i++){
            int cnt = 0;
            for(int j=0; j<bank[i].size(); j++){
                if(bank[i][j] == '1') cnt++;
            }
            if(cnt != 0) vec.push_back(cnt);
        }
        int ans = 0;
        for(int i=1; i<vec.size(); i++){
            ans += (vec[i]*vec[i-1]);
        }
        return ans;
    }
};