class Solution {
public:
    vector<vector<int>> dist;

    void fun(char sr, vector<vector<pair<char, int>>> &adj) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        pq.push({0,sr});
        dist[sr-'a'][sr-'a'] = 0;
        while(!pq.empty()) {
            int ind = pq.top().second - 'a';
            int dis = pq.top().first;
            pq.pop();
            for(auto it : adj[ind]) {
                char ch = it.first;
                int d = it.second;
                if(dis+d < dist[sr-'a'][ch-'a']) {
                    dist[sr-'a'][ch-'a'] = dis+d;
                    pq.push({dist[sr-'a'][ch-'a'], ch});
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();

        dist.resize(26, vector<int> (26, INT_MAX));
        vector<vector<pair<char, int>>> adj(26);
        for(int i=0; i<n; i++) {
            int u = original[i]-'a';
            int v = changed[i]-'a';
            int c = cost[i];
            adj[u].push_back({v+'a',c});
        }

        for(int i=0; i<26; i++){
            fun(i+'a', adj);
        }

        long long ans = 0;
        for(int i=0; i<source.size(); i++){
            int val = dist[source[i]-'a'][target[i]-'a'];
            if(val == INT_MAX) return -1;
            ans += val;
        }
        return ans;
    }
};