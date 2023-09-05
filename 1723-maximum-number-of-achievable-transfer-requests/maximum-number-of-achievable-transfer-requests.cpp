class Solution {
public:
    int solve(int i,int n,vector<int>& indegree,vector<vector<int>>& requests){
        if(i==requests.size()){
            for(int i = 0;i<n;i++){
                if(indegree[i]!=0) return -123456789;
            }
            return 0;
        }
        indegree[requests[i][0]] -= 1;
        indegree[requests[i][1]] += 1;
        int ans1 =  1 + solve(i+1,n,indegree,requests);
        indegree[requests[i][0]] += 1;
        indegree[requests[i][1]] -= 1;
        int ans2 = solve(i+1,n,indegree,requests);
        return max(ans1,ans2); 
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n);
        return solve(0,n,indegree,requests);
    }
};