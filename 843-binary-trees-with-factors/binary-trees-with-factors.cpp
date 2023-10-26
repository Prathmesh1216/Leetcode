class Solution {
public:
    unordered_map<long long,long long> mp;
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        sort(arr.begin(),arr.end());
        for(int i = 0;i<n;i++){
            mp[arr[i]]++;
            for(int j = 0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    if(mp.find(arr[i]/arr[j])!=mp.end()){
                        mp[arr[i]] += (mp[arr[j]]*mp[arr[i]/arr[j]])%mod;
                        mp[arr[i]] %= mod;
                    }
                }
            }
            ans += mp[arr[i]];
            ans%=mod;
        }
        
        return ans;
    }
};