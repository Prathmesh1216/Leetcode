class Solution {
public:
    int md(int r,int c,int tr,int tc){
        int xd = abs(r-tr);
        int yd = abs(c-tc);
        int ans = min(xd,yd);
        xd-=ans;
        yd-=ans;
        ans += xd+yd;
        return ans;
    }
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy && t==1) return false;
        return t>=md(sx,sy,fx,fy);
    }
};