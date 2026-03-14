class Solution {
public:
    vector<string>vec;
    void fun(string s, int n){
        if(s.size()==n){
            vec.push_back(s);
            return;
        }
        if(s[s.size()-1]=='a'){
        fun(s+"b", n);
        fun(s+"c", n);
        }
        else if(s[s.size()-1]=='b'){
            fun(s+"a", n);
            fun(s+"c", n);
        }
        else if(s[s.size()-1]=='c'){
            fun(s+"a", n);
            fun(s+"b", n);
        }
    }
    string getHappyString(int n, int k) {
        fun("a", n);
        fun("b", n);
        fun("c", n);
        sort(vec.begin(), vec.end());
        if(k>vec.size()) return "";
        return vec[k-1];
    }
};