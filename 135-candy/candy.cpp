class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n,1);
        for(int i = 1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]) ans[i] = 1 + ans[i-1];
        }
        for(int i = ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && ans[i]<=ans[i+1]) ans[i] = 1 + ans[i+1];
        }
        for(auto& it : ans) cout << it << endl;
        int a = accumulate(ans.begin(),ans.end(),0);
        return a;

    }
};