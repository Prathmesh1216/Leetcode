class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> v;
        for(int i = 0;i<position.size();i++){
            v.push_back({position[i],1.0*(target - position[i])/speed[i]});
        }
        sort(v.begin(),v.end());
        int ans = 0;
        double curr = 0;
        for(int i = position.size()-1;i>=0;i--){
            if(v[i].second>curr){
                curr = v[i].second;
                ans ++;
            }
        }
        return ans;
    }
};