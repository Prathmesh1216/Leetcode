class Solution {
public:
    // bool solve(int idx,bool turn,int sum,vector<int>& stones,vector<bool>& vis){
    //     if(idx!=0 && sum==0 && !turn) return true;
    //     if(idx==stones.size()) return false;
    //     if(!turn){
    //         bool flag = false;
    //        // bool played = false;
    //         for(int i = 0;i<stones.size();i++){
    //             if(!vis[i] && (sum + stones[i]%3)%3!=0){
    //                 vis[i] = 1;
    //                 flag = flag || solve(idx+1,1,(sum + stones[i]%3)%3,stones,vis);
    //                 vis[i] = 0;
    //             }
    //         }
    //         return flag;
    //     }
    //     bool flag = false;
    //     bool played = false;
    //     for(int i = 0;i<stones.size();i++){
    //             if(!vis[i] && (sum + stones[i]%3)%3!=0){
    //                 played = true;
    //                 vis[i] = 1;
    //                 flag = flag || solve(idx+1,0,(sum + stones[i]%3)%3,stones,vis);
    //                 vis[i] = 0;
    //             }
    //     }
    //     if(!played) return true;
    //     return flag;
    // }
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        for(int i = 0;i<n;i++){
            stones[i] = stones[i]%3;
        }
        int currsum = 0;
        int c1 = 0;
        int c2 = 0;
        int c0  = 0;
        for(int i = 0;i<n;i++){
            if(stones[i]==1) c1++;
            else if(stones[i]==2) c2++;
            else c0++;
        }
        if(c1==0 || c2==0) return max(c1,c2)>2 && c0%2>0;
        return abs(c1-c2)>2 || c0%2==0;

    }
};