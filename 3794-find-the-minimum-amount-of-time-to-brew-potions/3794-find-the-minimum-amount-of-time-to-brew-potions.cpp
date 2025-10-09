class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long> vec;
        int val = mana[0];
        vec.push_back(0);
        for(int i=0; i<skill.size(); i++){
            vec.push_back(vec[i]+(val*skill[i]));
        }
        for(int i=1; i<mana.size(); i++){
            int pro = mana[i];
            vec[0] = vec[1];
            int j;
            for( j=0; j<skill.size()-1; j++){
                vec[j+1] = max(vec[j+2], vec[j]+(pro*skill[j]));
            }
            vec[j+1] = vec[j]+(pro*skill[j]);
            for(int j=skill.size()-1; j>=0; j--){
                vec[j] = vec[j+1]-(pro*(skill[j]));
            }
        }
        return vec[vec.size()-1];
    }
};