class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int trav = 1;
        res.push_back({rStart, cStart});
        while(res.size() < rows*cols) {
            if(trav%2 == 1) {
                for(int i=1; i<=trav; i++){
                    if(cStart+i>=0 && cStart+i < cols && rStart>=0 && rStart<rows) {
                        res.push_back({rStart, cStart+i});
                        cout << rStart << " " << cStart+i << endl;
                    }
                }
                cStart += trav;
                for(int i=1; i<=trav; i++) {
                    if(rStart+i>=0 && rStart+i < rows && cStart>=0 && cStart<cols) {
                        res.push_back({rStart+i, cStart});
                        cout << rStart+i << " " << cStart << endl;
                    }
                }
                rStart += trav;
            }
            else {
                for(int i=1; i<=trav; i++) {
                    if(cStart-i >= 0 && cStart-i<cols && rStart>=0 && rStart<rows) {
                        res.push_back({rStart, cStart-i});
                        cout << rStart << " " << cStart-i << endl;
                    }
                }
                cStart -= trav;
                for(int i=1; i<=trav; i++) {
                    if(rStart-i >= 0 && rStart-i<rows && cStart>=0 && cStart<cols) {
                        res.push_back({rStart-i, cStart});
                        cout << rStart-i << " " << cStart << endl;
                    }
                }
                rStart -= trav;
            }
            trav++;
        }
        return res;
    }
};