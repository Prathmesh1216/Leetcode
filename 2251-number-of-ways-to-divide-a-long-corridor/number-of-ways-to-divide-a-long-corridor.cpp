class Solution {
public:
    int n;
    vector<int> ps;
    int mod = 1e9+7;
    int numberOfWays(string& corridor) {
        n = corridor.length();
        ps.resize(n);
        ps[0] = (corridor[0]== 'S');
        for(int i = 1;i<n;i++){
            if(corridor[i]=='S') ps[i] = 1;
            ps[i] += ps[i-1];
        }
        if(ps[n-1]&1) return 0;
        vector<int> ci;
        int c = 1;
        for(int i = 0;i<n;i++){
            if(ps[i] == 2*c){
                int kc = 1;
                int j = i + 1;
                while(j<n && corridor[j]!='S'){
                    kc++;
                    j++;
                }
                if(j!=n) ci.push_back(kc);
                c++;
            }
        }
        long long ans = 1;
       // for(auto& it : ci) cout << it << endl;
        if(ci.size()==0 && ps[n-1]>0) return 1;
        if(ci.size()==0) return 0;
        for(int i = 0;i<ci.size();i++){
            ans *= (ci[i]*1LL);
            ans %= mod;
        }
        return ans%mod;
    }
};