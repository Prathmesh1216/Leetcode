class Solution {
public:
    map<pair<int,int>,int> mp;
    int solve(int i,int turn,vector<int>& stoneValue){
        if(i>=stoneValue.size()) return false;
        int totscore;
        if(mp.find({i,turn})!=mp.end()) return mp[{i,turn}];
        if(!turn){
                totscore = INT_MIN;
                int currscore =0;
                for(int j = i;j<=i+2;j++){
                    if(j<stoneValue.size()){
                        currscore+=stoneValue[j];
                        totscore  = max(currscore+solve(j+1,1,stoneValue),totscore);
                    }
                }
                return mp[{i,turn}] = totscore;
        }
        if(turn){
            totscore = INT_MAX;
            int currscore = 0;
            for(int j = i;j<=i+2;j++){
                    if(j<stoneValue.size()){
                        currscore+=stoneValue[j];
                        totscore  = min(-currscore+solve(j+1,0,stoneValue),totscore);
                    }
                }
                return mp[{i,turn}] = totscore;
        }
        return 0;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int score = solve(0,0,stoneValue);
      //  memset(dp,-1,sizeof(dp));
        if(score>0) return "Alice";
        else if(score<0) return "Bob";
        return "Tie";
    }
};