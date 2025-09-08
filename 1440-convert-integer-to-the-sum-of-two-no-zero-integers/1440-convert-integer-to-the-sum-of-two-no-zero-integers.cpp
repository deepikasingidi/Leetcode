class Solution {
public:
    bool fun(int n){
        while(n > 0){
            if(n%10 == 0) return false;
            n /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<n; i++){
            int v1 = i;
            int v2 = n-i;
            if(fun(v1) && fun(v2)) return {v1,v2};
        }
        return {1,1};
    }
};