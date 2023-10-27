class Solution {
public:
    int n;
    int dp[20001][2];
    bool solve(int i,bool odd,vector<int>& ubs,vector<int>& lbs){
        if(i==n-1) return true;
        if(dp[i][odd]!=-1) return dp[i][odd];
        if(odd){
            if(ubs[i]!=-1) return solve(ubs[i],!odd,ubs,lbs);
            return false;
        }
        if(lbs[i]!=-1) return solve(lbs[i],!odd,ubs,lbs);
        return false;
    }
    int oddEvenJumps(vector<int>& arr) {
        set<int> st;
        unordered_map<int,int> mp;
        n = arr.size();
        vector<int> lbs(n,-1),ubs(n,-1);
        st.insert(arr[n-1]);
        mp[arr[n-1]] = n-1;
        for(int i = n-2;i>=0;i--){
            auto it = st.lower_bound(arr[i]);
            if(it!=st.end() && *it>=arr[i]){
                ubs[i] = mp[*it];
            }
            if((it==st.end() || *it>arr[i]) && it!=st.begin()){
                it--;
            }
            if(it!=st.end() && *it<=arr[i]){
                lbs[i] = mp[*it];
            }
            mp[arr[i]] = i;
            st.insert(arr[i]);
        }
        memset(dp,-1,sizeof(dp));
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(solve(i,1,ubs,lbs)) cnt++;
        }
        return cnt;


    }
};