class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& vec, int es) {
        priority_queue<
            pair<double, pair<int, int>>> pq;
        

        for(auto it : vec) {
            int s = it[0];
            int t = it[1];

            double diff = abs((double)(s+1)/(t+1)-(double)s/t);
            pq.push({diff,{it[0],it[1]}});
        } 

        // while(!pq.empty()) {
        //     cout << pq.top().second.first << " " << pq.top().second.second;
        //     pq.pop();
        // }

        while(es > 0) {
            auto top = pq.top();
            pq.pop();
            int s = top.second.first;
            int t = top.second.second;
            double diff = (double)(s+2)/(t+2)-(double)(s+1)/(t+1);
    
            pq.push({diff,{s+1,t+1}});
            es--;

        }

         double sum = 0;
        while(!pq.empty()){
            auto top = pq.top();
            int first = top.second.first;
            int second = top.second.second;
            
            double ans = (double)first/second;
            sum += ans;
            pq.pop();
        }
        
        return sum/vec.size();
    }
};