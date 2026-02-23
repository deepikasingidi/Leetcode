class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        string str = "";
        int n = s.size();
        if(n < k) return false;
        for(int i=0; i<k; i++) {
            str += s[i];
        }
        st.insert(str);
        for(int i=k; i<n; i++) {
            str.erase(0,1);
            str += s[i];
            st.insert(str);
        }
        if(st.size() == pow(2,k)) return true;
        return false;
    }
};