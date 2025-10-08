class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n,-1);
        vector<int> vec;
        map<int, int> mp;
        for(int i=0; i<n; i++){
            if(mp[rains[i]]==0 && rains[i]!=0) mp[rains[i]] = i+1;
            else if(rains[i] == 0) vec.push_back(i);

            else if(mp[rains[i]] != 0 && vec.size() > 0){
                bool flag = false;
                for(int j=0; j<vec.size(); j++){
                    if(vec[j] > mp[rains[i]]-1){
                        ans[vec[j]] = rains[i];
                        vec.erase(vec.begin()+j);
                        mp[rains[i]] = i+1;
                        flag = true;
                        break;
                    }
                }
                if(!flag) return {};
            }
            else return {};
        }
        if(vec.size() > 0) {
            for(int i=0; i<vec.size(); i++){
                ans[vec[i]] = 1;
            }
        }
        return ans;
    }
};