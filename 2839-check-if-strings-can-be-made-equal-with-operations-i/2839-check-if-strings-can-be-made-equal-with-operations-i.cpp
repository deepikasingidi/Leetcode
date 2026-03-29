class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2) return true;
        string t1 = s1;
        swap(t1[0], t1[2]);
        string t2 = s1;
        swap(t2[1], t2[3]);
        string t3 = t1;
        swap(t3[1], t3[3]);

        if(t1==s2 || t2==s2 || t3==s2) return true;

        string r1 = s2;
        swap(r1[0], r1[2]);
        if(t1==r1 || t2==r1 || t3==r1) return true;
        string r2 = s2;
        swap(r2[1], r2[3]);
        if(t1==r2 || t2==r2 || t3==r2) return true;
        string r3 = r1;
        swap(r3[1], r3[3]);
        if(t1==r3 || t2==r3 || t3==r3) return true;

        return false;
    }
};