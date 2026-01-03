class Solution {
public:
    vector<string> res;
    void fun(int n, string &str) {
        if(str.size() == n) {
            res.push_back(str);
            return;
        }

        if(str[str.size()-1] == '0'){
            str += '1';
            fun(n, str);
            str.pop_back();
        }
        else if(str[str.size()-1] == '1') {
            str += '0';
            fun(n, str);
            str.pop_back();

            str += "1";
            fun(n, str);
            str.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        string str = "0";
        fun(n, str);
        str.pop_back();

        str = "1";
        fun(n, str);

        return res;
    }
};