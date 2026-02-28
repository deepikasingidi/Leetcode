class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0; i<n; i++) {
            if(s[i] != ']') st.push(s[i]);
            else {
                string temp = "";
                while(st.top() != '[') {
                    temp = st.top()+temp;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && st.top()>='0' && st.top()<='9') {
                    num = st.top() + num;
                    st.pop();
                }

                int val = stoi(num);
                while(val--) {
                    for(auto ch : temp) st.push(ch);
                }
            }
        }

        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};