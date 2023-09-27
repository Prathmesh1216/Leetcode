class Solution {
public:
    int dist(int x1,int y1,int x2,int y2){
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        vector<map<int,int>> v(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i==j) continue;
                int dis = dist(points[i][0],points[i][1],points[j][0],points[j][1]);
                v[i][dis]++;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(auto& it : v[i]){
                int val = it.second;
                ans += (val)*(val-1);
            }
        }
        return ans;

    }
};