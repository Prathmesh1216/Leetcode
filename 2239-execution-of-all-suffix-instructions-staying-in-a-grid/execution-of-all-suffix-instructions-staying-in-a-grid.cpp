class Solution {
public:
    int n,m;
    vector<int> executeInstructions(int N, vector<int>& startPos, string s) {
        n = N,m = s.length();
        vector<int> ans;
        for(int i = 0;i<s.length();i++){
            int r = startPos[0];
            int c = startPos[1];
            int cnt = 0;
            int j;
            for( j = i;j< s.length();j++){
                if(s[j]=='L') c--;
                else if(s[j]=='R') c++;
                else if(s[j]=='U') r--;
                else r++;
                if(r<0 || r>=n || c<0 || c>=n){
                    ans.push_back(cnt);
                    break;
                }
                cnt++;
            }
            if(j==m) ans.push_back(cnt);
        }
        return ans;
    }
};