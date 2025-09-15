class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> vec;
        stringstream ss(text);
        string token;
        while(getline(ss, token, ' ')){
            vec.push_back(token);
        }
        int cnt = vec.size();
        for(int i=0; i<vec.size(); i++){
            for(int j=0; j<vec[i].size(); j++){
                if(brokenLetters.find(vec[i][j]) != string::npos){
                    cnt--;
                    break;
                }
            }
        }
        return cnt;
    }
};