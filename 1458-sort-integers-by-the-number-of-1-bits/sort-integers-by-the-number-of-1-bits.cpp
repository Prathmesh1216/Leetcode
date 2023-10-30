class Solution {
public:
    int cbits(int n){
        int cnt = 0;
        while(n) {if(n&1) cnt++; n = n>>1;};
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> v(n);
        for(int i = 0;i<n;i++){
            v[i] = {cbits(arr[i]),arr[i]};
        }
        sort(v.begin(),v.end());
        for(int i = 0;i<n;i++) arr[i] = v[i].second;
        return arr;
    }
};