class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]>b[1];
    }
    int lb(int x,vector<int>& a){
        int start = 0;
        int end = a.size()-1;
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(a[mid]>=x){
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return ans;
    }
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> v(101);
        for(auto& it : rectangles){
            v[it[1]].push_back(it[0]);
        }
        for(auto& it : v) sort(it.rbegin(),it.rend());
        vector<int> ans;
        for(auto& it : points){
            int cnt = 0;
            for(int i = 100;i>=0;i--){
                if(i<it[1]) break;
                int t = lb(it[0],v[i]);
                cnt += (t+1);
            }
            ans.push_back(cnt);
        }
        return ans;

    }
};