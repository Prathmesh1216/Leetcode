class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int>t;
        for(int i=0;i<dist.size();i++){
            t.push_back((dist[i]+speed[i]-1)/speed[i]);
        }
        sort(t.begin(),t.end());
        int time=1;
        int ans=1;
        for(int i=1;i<dist.size();i++){
            t[i]-=time;
            if(t[i]>0){
                ans++;
                time++;
            }
            else break;
        }
        return ans;
    }
};