class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        map<int,vector<int>> mp;
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<long long> ans(arr.size());
        for(auto it : mp){
            auto v = it.second;
            long long sum = 0;
            int a = v.size();
            long long tsum = accumulate(v.begin(),v.end(),(long long)0);
            cout << tsum << endl;
            for(int i = 0;i<a;i++){
                ans[v[i]] += i*1LL*v[i] - sum;
                sum +=v[i];
            }
            sum = 0;
            for(int i = a-1;i>=0;i--){
                ans[v[i]] += sum - (a-1-i)*1LL*v[i];
                sum += v[i];
            }
        }
        return ans;
    }
};