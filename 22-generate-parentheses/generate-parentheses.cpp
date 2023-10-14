class Solution {
public:
    vector<string> ans;
    void solve(int i,int oc,int cc,string& path,int n){
        if(i==n){
            if(oc==cc) ans.push_back(path);
            return;
        }
        path.push_back('(');
        solve(i+1,oc+1,cc,path,n);
        path.pop_back();
        if(oc>cc){
            path.push_back(')');
            solve(i+1,oc,cc+1,path,n);
            path.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        n = 2*n;
        string path = "";
        solve(0,0,0,path,n);
        return ans;
    }
};