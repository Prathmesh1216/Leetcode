class Solution {
public:
    const int m = 1e9+7;
    long long power(long long n,long long a){
        if(a==0) return 1;
        if(a&1) return ((n%m)*(power(n,a-1)%m))%m;
        return power((n*n)%m,a/2)%m;
    }
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        stack<pair<int,int>> st;
        for(auto& it : ranges){
            if(!st.empty() && st.top().second>=it[0]){
                pair<int,int> a = st.top();
                st.pop();
                st.push({a.first,max(a.second,it[1])});
            }
            else st.push({it[0],it[1]});
        }
        return power(2,st.size());
    }
};