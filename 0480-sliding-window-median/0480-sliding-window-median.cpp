class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<long long> lo, hi;
        auto balance = [&] () {
            if(lo.size() > hi.size()+1){
                hi.insert(*lo.rbegin());
                lo.erase(prev(lo.end()));
            }
            if(hi.size() > lo.size()){
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
        };
        for(int i=0; i<nums.size(); i++){
            if(lo.empty() || nums[i]<=*lo.rbegin()) lo.insert(nums[i]);
            else hi.insert(nums[i]);
            balance();
            if(i >= k){
                int val = nums[i-k];
                if(val<=*lo.rbegin()) lo.erase(lo.find(val));
                else hi.erase(hi.find(val));
                balance();
            }
            if(i >= k-1){
                if(k%2==1) ans.push_back((double)*lo.rbegin());
                else ans.push_back(((double)*lo.rbegin()+(double)*hi.begin())/2.0);
            }
        }
        return ans;
    }
};