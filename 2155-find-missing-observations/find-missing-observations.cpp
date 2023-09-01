class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int tsum = (m+n)*mean;
        int sum = 0;
        for(auto it : rolls) sum += it;
       // cout << 1 << endl;
        if(tsum<=sum) return {};
        tsum -= sum;
        if(tsum>(6*n) || tsum<n) return {};
        int a = tsum/n;
        int rem = tsum%n;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            ans.push_back(a);
            if((rem--)>0) ans[i]++;
        }
        return ans;
    }
};