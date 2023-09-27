class Solution {
public:
    vector<int> ans;
    int target = 0;
    void solve(int i,int sum,int na,vector<int>& temp,vector<int>& aa){
        if(i==-1 || na<=0){
            if(sum>target){
                target = sum;
                if(na>0) temp[0] += na;
                ans = temp;
            }
            return;
        }
        if(aa[i]+1<=na){
            temp[i] = aa[i] + 1;
            solve(i-1,sum + i,na-aa[i]-1,temp,aa);
            temp[i] = 0;
        }
        solve(i-1,sum,na,temp,aa);
        return;
    }
    vector<int> maximumBobPoints(int na, vector<int>& aa) {
        vector<int> temp(12,0);
        solve(11,0,na,temp,aa);
        return ans;
    }
};