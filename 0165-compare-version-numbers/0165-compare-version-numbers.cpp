class Solution {
public:
    int compareVersion(string version1, string version2) {
        int cnt1=0, cnt2=0;
        for(int i=0; i<version1.size(); i++){
            if(version1[i]=='.') cnt1++;
        }
        for(int i=0; i<version2.size(); i++){
            if(version2[i]=='.') cnt2++;
        }
        int size = max(cnt1, cnt2);
        vector<int> v1(size+1,0);
        vector<int> v2(size+1,0);
        int p1=0, p2=0;
        string s = "";
        for(int i=0; i<version1.size(); i++){
            if(version1[i]=='.') {
                v1[p1] = stoi(s);
                s = "";
                p1++;
            }
            else s+= version1[i];
        }
        v1[p1] = stoi(s);
        s = "";
        for(int i=0; i<version2.size(); i++){
            if(version2[i]=='.'){
                v2[p2] = stoi(s);
                s = "";
                p2++;
            }
            else s += version2[i];
        }
        v2[p2] = stoi(s);
        for(int i=0; i<size+1; i++){
            if(v1[i] < v2[i]) return -1;
            if(v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};