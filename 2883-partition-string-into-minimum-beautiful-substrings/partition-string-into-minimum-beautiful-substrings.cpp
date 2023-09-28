  class Solution {
public:
bool check(string &a,int i,int j){
    int num=0;
     for(int k = i;k<=j;k++){
            if(a[k]=='1') num += pow(2,j-k);
        }
    while(num>1){
        if(num%5!=0) return false;
        num/=5;
    }
    return num==1;
}

int f(int s,string &st,vector<int> &dp){
    if(s==st.size()) {
        return 0;
    }
    if(dp[s]!=-1) return dp[s];
    int ans=1e9;
    for(int i=s;i<st.size();i++){
        if(st[s]=='0') continue;
        if(check(st,s,i)) {
            ans=min(ans,1+f(i+1,st,dp));
        }


    }
    return dp[s]=ans;
}

   int minimumBeautifulSubstrings(string s) {
        int n=s.size();
      
    vector<int> dp(n,-1);
        int ans=f(0,s,dp);
       return ans>=1e9 ? -1:ans;
       

    }
};