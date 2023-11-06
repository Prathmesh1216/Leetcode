class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int cnt = 1;
        int cs = points[0][0],ce = points[0][1];
        for(int i = 1;i<points.size();i++){
            if(points[i][0]<=ce){
                cs = points[i][0];
                ce = min(points[i][1],ce);
            }
            else{
                cnt ++;
                cs = points[i][0];
                ce = points[i][1];
            }
        }
        return cnt;
    }
};