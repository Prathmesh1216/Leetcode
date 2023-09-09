class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 1;
        int maxi = neededTime[0];
        int time = neededTime[0];
        int ans = 0;
        int n = colors.size();
        while(i<colors.size()){
            while(i<n && colors[i] == colors[i-1]){
                time += neededTime[i];
                maxi = max(neededTime[i],maxi);
                i++;
            }
           // cout << ans << endl;
            ans += (time-maxi);
            time = neededTime[i];
            maxi = neededTime[i];
            i++;

        }
        return ans;
        
    }
};