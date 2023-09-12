class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26);
        for(auto& it : s) v[it-'a']++;
        unordered_map<int,int> mp;
        int cnt = 0;
        for(auto& it : v){
            if(it>0){
                if(mp.find(it)==mp.end()){
                    mp[it]++;
                    continue;
                }
                else{
                    int a = it;
                    while(mp.find(a)!=mp.end()){
                        a--;
                        cnt++;
                    } 
                    if(a>0) mp[a]++;
                 }
            }
        }
        return cnt;


    }
};