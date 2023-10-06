class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arr, vector<int>& load) {
        set<int> st;
        for(int i = 0;i<k;i++) st.insert(i);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        long long time = 0;
        vector<int> v(k);
        for(int i = 0;i<arr.size();i++){
            
            while(!pq.empty() && pq.top().first<=arr[i]){
                st.insert(pq.top().second);
                pq.pop();
            }
            if(st.empty()) continue;
            auto it = st.lower_bound(i%k);
            cout << *it << endl;
            if(it==st.end()){
                v[*st.begin()]++;
                pq.push({arr[i]+load[i],*st.begin()});
                st.erase(*st.begin());
            }
            else{
                v[*it]++;
                pq.push({arr[i]+load[i],*it});
                st.erase(*it);
            }
        }
        vector<int> ans;
        int maxi = *max_element(v.begin(),v.end());
        for(int i = 0;i<v.size();i++){
            if(v[i]==maxi) ans.push_back(i);
        }
        return ans;
    }
};