class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int>t;
        for(int i=0;i<dist.size();i++){
            dist[i] = (dist[i]-1)/speed[i];
        }
        sort(dist.begin(),dist.end());
        for(int i=0;i<dist.size();i++){
            if(i>dist[i]) return i;
        }
        return dist.size();
    }
};