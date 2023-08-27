class Solution {
public:
    map<pair<int,int>,int> dp;
    bool solve(int pos,int last,set<int>& st,int target){
        if(pos == target) return true;
        bool flag = false;
        // st.erase(pos);
        if(dp.find({pos,last})!=dp.end()) return dp[{pos,last}];
        if(last == 0 && st.find(pos+1)!=st.end()) flag = flag || solve(pos+1,1,st,target);
        else{

        if(st.find(pos + last-1)!=st.end() && (pos + last-1)!=pos) flag = flag || solve(pos+last-1,last-1,st,target);
        if(st.find(pos + last)!=st.end() && (pos + last)!=pos) flag = flag || solve(pos+last,last,st,target);
        if(st.find(pos+last+1)!=st.end() && (pos + last+1)!=pos) flag = flag || solve(pos+last+1,last+1,st,target);
        // st.insert(pos);
        }
        return dp[{pos,last}] = flag;
    }
    bool canCross(vector<int>& stones) {
        set<int> st(stones.begin(),stones.end());
        int target = stones[stones.size()-1];
       // st.erase(0);
        return solve(0,0,st,target);
    }
};