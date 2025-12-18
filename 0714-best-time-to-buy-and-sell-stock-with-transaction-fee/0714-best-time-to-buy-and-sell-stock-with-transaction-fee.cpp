class Solution {
public:
int dp[100000][2];
    int Fun(int i, bool flage, vector<int>&p, int fee, int n){
        if(i >= n) return 0;
        if(dp[i][flage]!=-1) return dp[i][flage];
        if(flage == false){
            return dp[i][flage]=max(-1*p[i] + Fun(i+1,!flage,p,fee,n), Fun(i+1,flage,p,fee,n));
        }
        else{
            return dp[i][flage] = max((p[i]-fee) + Fun(i+1,!flage,p,fee,n),Fun(i+1,flage,p,fee,n));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<long long> peaks;
        vector<long long> lows;
        bool flage = false;
        if(n==1) return 0;
        memset(dp,-1,sizeof(dp));
        return Fun(0,flage,prices,fee,n);

        // if(prices[0] < prices[1]) lows.push_back(prices[0]);
        // for(int i=1; i<n-1; i++){
        //     if(prices[i] <= prices[i-1] && prices[i] < prices[i+1]) lows.push_back(prices[i]);
        //     if(prices[i] >= prices[i+1] && prices[i] > prices[i-1]) peaks.push_back(prices[i]);
        // }
        // if(prices[n-1] > prices[n-2]) peaks.push_back(prices[n-1]);

        
        // if(lows.size()==0 || peaks.size()==0) return 0;

        // int m = peaks.size();

        // cout << peaks.size() << " " << lows.size() << endl;
        // vector<long long> dp(m+1, 0);
        // vector<long long> curr(m+1, 0);
        // int i=1;
        // while(i<=m){
        //     for(int j=i; j<=m; j++) {
        //         // cout << i-1 << " " << j << " " << j-1 << endl;
        //         curr[j] = max({dp[j], peaks[j-1]-lows[i-1]-fee+dp[i-1]});
        //     }
        //     dp = curr;
        //     i++;
        // }

        // // cout << "Peaks" << endl;
        // // for(int i=0; i<peaks.size(); i++) cout << peaks[i] << " ";

        // // cout << "\nLows" << endl;
        // // for(int i=0; i<lows.size(); i++) cout << lows[i] << " ";

        // // cout << endl << endl;

        // // for(int i=0; i<=m; i++){
        // //     for(int j=0; j<=m; j++) {
        // //         cout << dp[i][j] << " ";
        // //     }
        // //     cout << endl;
        // // }
        //return dp[m];
    }
};