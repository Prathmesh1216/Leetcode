class Solution {
public:
    int solve(int i,int mask,int m,vector<vector<int>>& comp){
        if(i==m) return 0;
        int ans  = 0;
        for(int j = 0;j<m;j++){
            if(!(mask&(1<<j))) ans = max(ans,comp[i][j] + solve(i+1,mask|(1<<j),m,comp));
        }
        return ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        vector<vector<int>> comp(m,vector<int>(m,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<m;j++){
                for(int k = 0;k<n;k++){
                    if(students[i][k]==mentors[j][k]) comp[i][j]++;
                }
            }
        }
        // for(int i = 0;i<m;i++){
        //     for(int j = 0;j<m;j++){
        //         cout << comp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return solve(0,0,m,comp);
    }
};