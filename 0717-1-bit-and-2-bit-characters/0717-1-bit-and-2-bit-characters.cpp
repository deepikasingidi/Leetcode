class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        vector<int> chars;
        int i=0;
        while(i<n){
            if(bits[i] == 1) {
                if(bits[i+1] == 1) chars.push_back(11);
                else chars.push_back(10);
                i+=2;
            }
            if(i<n && bits[i] == 0){
                chars.push_back(0);
                i++;
            }
        }
        if(chars[chars.size()-1] == 0) return true;
        return false;
    }
};