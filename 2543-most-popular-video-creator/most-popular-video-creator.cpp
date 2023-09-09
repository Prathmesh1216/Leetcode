class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,long long> mp;
        map<string,vector<pair<string,long long>>> ans;
        long long maxi =0;
        for(int i=0;i<ids.size();i++){
            mp[creators[i]]+=views[i];
            maxi=max(maxi, mp[creators[i]]);
            ans[creators[i]].push_back({ids[i],views[i]});
        }
        vector<vector<string>> fans;
        for(auto x:mp)
        {
            if(x.second==maxi)
            {
                string p=ans[x.first][0].first;
                long long q=ans[x.first][0].second;
                for(auto b:ans[x.first])
                {
                 if(b.second>q)
                 {p=b.first;
                  q=b.second;}
                 else if(b.second==q && p>b.first)
                     p=b.first;  
                }
                vector<string> s;
                s.push_back(x.first);
                s.push_back(p);
                fans.push_back(s);
            }
                
        }
        
        return fans;
    }
};