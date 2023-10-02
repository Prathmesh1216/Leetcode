class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> st,st1;
        int n = rains.size();
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            if(rains[i]>0) ans[i] = -1;
        }
        unordered_map<int,int> li;
        for(int i = 0;i<n;i++){
            if(rains[i]>0){
                if(st.find(rains[i])==st.end()) st.insert(rains[i]);
                else{
                    if(st1.empty()) return {};
                    auto it = st1.lower_bound(li[rains[i]]);
                    if(it==st1.end()) return {};
                        ans[*it] = rains[i];
                        st1.erase(it);
                }
            }
            else{
                st1.insert(i);
            }
            li[rains[i]] = i;
        }
        for(int i = 0;i<n;i++) if(ans[i]==0) ans[i] = 1;
        return ans;
    }
};