class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        int i = 0;
        int j = 0;
        int n = fl.size(),m = sl.size();
        vector<vector<int>> ans;
        while(i<n && j<m){
            if(fl[i][0]>sl[j][1]) j++;
            else if(sl[j][0]>fl[i][1]) i++;
            else if(fl[i][1]>=sl[j][0]){
                vector<int> v(2);
                v[0] = max(sl[j][0],fl[i][0]);
                if(sl[j][1]==fl[i][1]){
                    v[1] = fl[i][1];
                    i++;
                    j++;
                }
                else if(sl[j][1]<fl[i][1]){
                    v[1] = sl[j][1];
                    j++;
                }
                else{
                    v[1] = fl[i][1];
                    i++;
                }
                ans.push_back(v);
            }
            else if(sl[j][1]>=fl[i][0]){
                vector<int> v(2);
                v[0] = max(fl[i][0],sl[j][0]);
                if(fl[i][1]==sl[j][1]){
                    v[1] = sl[j][1];
                    i++;
                    j++;
                }
                else if(fl[i][1]<sl[j][1]){
                    v[1] = fl[i][1];
                    i++;
                }
                else{
                    v[1] = sl[j][1];
                    j++;
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
}; 