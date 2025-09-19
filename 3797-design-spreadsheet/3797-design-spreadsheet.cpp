class Spreadsheet {
public:
    unordered_map<string, int> mp;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string str) {
        string formula = str.substr(1);
        vector<string> vec;
        stringstream ss(formula);
        string token;
        while(getline(ss, token, '+')){
            vec.push_back(token);
        }
        char ch1 = vec[0][0];
        char ch2 = vec[1][0];
        if((ch1 >= 'A' && ch1 <= 'Z') && (ch2 >= 'A' && ch2 <= 'Z')){
            return mp[vec[0]]+mp[vec[1]];
        }
        else if((ch1 >= 'A' && ch1 <= 'Z') && !(ch2 >= 'A' && ch2 <= 'Z')){
            int num = stoi(vec[1]);
            return mp[vec[0]]+num;
        }
        else if(!(ch1 >= 'A' && ch1 <= 'Z') && (ch2 >= 'A' && ch2 <= 'Z')){
            int num = stoi(vec[0]);
            return mp[vec[1]]+num;
        }
        else {
            int num1 = stoi(vec[0]);
            int num2 = stoi(vec[1]);
            return num1+num2;
        }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */