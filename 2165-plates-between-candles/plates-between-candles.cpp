class Solution {
public:
    int lo(int t,vector<int>& v){
        int ans = -1;
        int start = 0;int end = v.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(v[mid]<=t){
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return ans;
    }
    int fo(int t,vector<int>& v){
        int ans = -1;
        int start = 0;int end = v.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(v[mid]>=t){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> v;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='|') v.push_back(i);
        }
        vector<int> ans;
        for(auto& it : queries){
            int i = fo(it[0],v);int j = lo(it[1],v);
            if(i==-1 || j==-1 || i>=j){
                ans.push_back(0);continue;
            }
            ans.push_back(v[j] - v[i] - (j - i));
        }
        return ans;
    }
};