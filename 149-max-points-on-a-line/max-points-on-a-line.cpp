class Solution {
public:
    double slope(vector<int>& a,vector<int>& b){
        if(b[0]==a[0]) return 123456789;
        return (1.0*(b[1]-a[1]))/(b[0]-a[0]);
    }
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double,int> mp;
        int ans = 1;
        for(int i  = 0;i<points.size();i++){
            mp.clear();
            for(int j = i+1;j<points.size();j++){
                double s = slope(points[i],points[j]);
                mp[s]++;
                ans = max(ans,mp[s]+1);
            }
        }
        return ans;
    }
};