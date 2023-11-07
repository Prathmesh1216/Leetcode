class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> v;
        for(int i = 0;i<n;i++) v.push_back(1.0*dist[i]/speed[i]);
        sort(v.begin(),v.end());
        int t = 0;
        for(int i = 0;i<n;i++){
            if(t<v[i]){
                t++;
            }
            else break;
        }
        return t;

    }
};