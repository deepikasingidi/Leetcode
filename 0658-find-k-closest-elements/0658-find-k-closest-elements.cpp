class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        
        vector<int> res;
        if(lb == 0) {
            for(int i=0; i<k; i++) {
                res.push_back(arr[i]);
            }
            return res;
        }
        else if(lb >= n) {
            for(int i=n-k; i<n; i++){
                res.push_back(arr[i]);
            }
            return res;
        }

        int i=lb, j = lb;
        if(arr[lb] != x) i = lb-1;
        else {
            res.push_back(x);
            i = lb-1;
            j = lb+1;
            k--;
        }

        while(k>0 && i>=0 && j<n) {
            if(abs(x-arr[i]) <= abs(x-arr[j])) {
                res.push_back(arr[i]);
                i--;
            }
            else {
                res.push_back(arr[j]);
                j++;
            }
            k--;
        }    
        while(k>0 && i>=0) {
            res.push_back(arr[i]);
            i--;
            k--;
        }
        while(k>0 && j<n) {
            res.push_back(arr[j]);
            j++;
            k--;
        }
        sort(res.begin(), res.end());
        return res;
    }
};