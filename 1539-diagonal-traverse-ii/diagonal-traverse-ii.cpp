class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> v;
        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<nums[i].size();j++){
                v.push_back({i+j,i,nums[i][j]});
            }
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        for(auto& it : v) ans.push_back(it[2]);
        return ans;
    }
};