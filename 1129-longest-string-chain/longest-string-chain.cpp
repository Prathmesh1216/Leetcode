class Solution {
public:
    static bool comp(string &s1,string &s2){
        return s1.length()<s2.length();
    }
    bool compare(string &s1,string &s2){
        if(s1.size()!=s2.size()+1){
            return false;
        }
        int i = 0;
        int j = 0;
        while(i<s1.length()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j==s2.size()){
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& arr) {
        int n = arr.size();
        vector<int> dp(n,1);
        sort(arr.begin(),arr.end(),comp);
        int mx = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(compare(arr[i],arr[j]) && 1 + dp[j]>dp[i]){
                    dp[i] = 1 + dp[j];
                }
            }
            mx = max(dp[i],mx);
        }
        return mx;

    }
};
