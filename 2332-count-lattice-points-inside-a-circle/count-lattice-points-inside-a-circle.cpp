class Solution {
public:
    int dis(int x1,int y1,int x2,int y2){
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    }
    int countLatticePoints(vector<vector<int>>& circles) {
        int cnt = 0;
        for(int i = 0;i<=200;i++){
            for(int j = 0;j<=200;j++){
                bool flag = false;
                for(int k = 0;k<circles.size();k++){
                    if(dis(i,j,circles[k][0],circles[k][1]) <= circles[k][2]*circles[k][2]) flag = true;
                    if(flag){
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};