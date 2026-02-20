class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> right_max(n,INT_MIN);
        set<int> s;
        for(int i=n-1; i>=0; i--) {
            auto lb = s.lower_bound(nums[i]);
            if(lb != s.begin()){
                lb--;
                if(*lb-1 < nums[i]) right_max[i] = *lb;
            }
            s.insert(nums[i]);
        }

        vector<int> left_min(n,INT_MAX);
        set<int> s1;
        for(int i=0; i<n; i++) {
            if(!s1.empty() && *s1.begin()<nums[i]) {
                left_min[i] = *s1.begin();
            }
            s1.insert(nums[i]);
        }

        for(int i=0; i<n; i++) {
            cout << i <<" -> "<< nums[i] <<" "<< left_min[i] <<" "<< right_max[i] << endl;
            if(left_min[i] < right_max[i]) return true;
        }
        return false;
    }
};