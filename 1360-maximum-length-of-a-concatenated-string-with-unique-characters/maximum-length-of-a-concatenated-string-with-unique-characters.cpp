class Solution {
public:
    map<string,int> dp;
    bool isValid(string s){
      //  cout << s << " ";
        vector<int> arr(26);
        for(auto it : s){
            arr[it-'a']++;
            if(arr[it-'a']>1) return false;
        }
        return true;
    }
    int solve(int i,int n,vector<string>& arr,string temp){
        if(i==n){
            return temp.length();
        }
        if(dp.find(temp)!=dp.end()) return dp[temp];
        if(isValid(temp+arr[i])) return dp[temp] = max(solve(i+1,n,arr,temp+arr[i]),solve(i+1,n,arr,temp));
        else return dp[temp] = solve(i+1,n,arr,temp);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        return solve(0,n,arr,"");
    }
};