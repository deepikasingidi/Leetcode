class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        string temp = s;
        for(int i=0; i<n; i++){
            int k = k%n;
            temp = temp.substr(1) + temp[0];
            if(temp == goal) return true;
        }
        return false;
    }
};