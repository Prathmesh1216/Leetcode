class Solution {
public:
    
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long ans = 0;
        unordered_map<long long,long long> mp;
        for(int& it : tasks){
            if(mp.find(it)==mp.end()){
                mp[it] = ans;
            }
            else if(ans - mp[it]>space){
                mp[it] = ans;
            }
            else{
                mp[it] = mp[it]+space+1;
                ans = mp[it];
            }
            ans++;
        }
        return ans;
    }
};