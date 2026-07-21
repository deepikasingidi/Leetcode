class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {  
        int prev= 0, maxi = 0, one = 0 , curr = 0;
         for(int i=0; i<s.size(); i++){
                if(s[i] == '1') {
                    if(curr != 0){
                      if(prev != 0)  maxi = maxi > prev + curr ? maxi : prev + curr;
                        prev = curr;
                        curr = 0;
                    }
                    one++;
                }
                if(s[i] == '0') curr++;
         }
         if(prev != 0 && curr !=0) maxi = maxi > prev + curr ? maxi : prev + curr;
         return maxi+one;
    }
};