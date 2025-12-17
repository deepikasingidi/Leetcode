class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string r1="", i1="", r2="", i2="";
        int i=0; 
        while(num1[i] != '+') {
            r1 += num1[i];
            i++;
        }
        i++;
        while(num1[i] != 'i') {
            i1 += num1[i];
            i++;
        }
        i=0;
        while(num2[i] != '+') {
            r2 += num2[i];
            i++;
        }
        i++;
        while(num2[i] != 'i') {
            i2 += num2[i];
            i++;
        }

        int a1 = stoi(r1), b1 = stoi(i1), a2 = stoi(r2), b2 = stoi(i2);
        int v1  = (a1*a2) - (b1*b2);
        int v2 = (a1*b2)+(a2*b1);

        string res = to_string(v1) + "+" + to_string(v2) + "i";
        return res;
    }
};