class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        vector<vector<int>>res;
        map<int,vector<int>>mp;
        for(int i=0;i<group.size();i++){
            mp[group[i]].push_back(i);
        }

        for(auto it:mp){
            vector<int>temp;
            for(int j=0;j<it.second.size();j++){
                temp.push_back(it.second[j]);
                if(temp.size() == it.first){
                    res.push_back(temp);
                    temp.clear();
                }
                
            }
        }
        return res;
    }
};