class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> v;
        for(int i = 0;i<n;i++){
            if(directions[i]=='L') v.push_back({positions[i],healths[i],0,i});
            else v.push_back({positions[i],healths[i],1,i});
        }
        sort(v.begin(),v.end());
       // for(auto it : v) cout << it[0] << endl;
        stack<vector<int>> st;
        for(int i = 0;i<n;i++){
            vector<int> temp = v[i];
            if(st.size()>0 && st.top()[2]==1 && temp[2]==0 && temp[1]<st.top()[1]){
                vector<int> temp2 = st.top();
                st.pop();
                temp2[1]--;
                if(temp2[1]>0) st.push(temp2);
                continue;
            }
            while(st.size()>0 && st.top()[2]==1 && temp[2]==0 && temp[1]>st.top()[1]){
                st.pop();
                temp[1]--;
            }
            if(st.size()>0 && st.top()[2]==1 && temp[2]==0 && temp[1]==st.top()[1]){
                st.pop();
                continue;
            }
            if(st.size()>0 && st.top()[2]==1 && temp[2]==0 && temp[1]<st.top()[1]){
                vector<int> temp2 = st.top();
                st.pop();
                temp2[1]--;
                if(temp2[1]>0) st.push(temp2);
                continue;
            }
            st.push(temp);
        }
        vector<pair<int,int>> ans;
        while(!st.empty()){
            ans.push_back({st.top()[3],st.top()[1]});
            st.pop();
        }
       sort(ans.begin(),ans.end());
       vector<int> fans(ans.size());
       for(int i = 0;i<ans.size();i++){
           fans[i] = ans[i].second;
       }
        return fans;
    }
};