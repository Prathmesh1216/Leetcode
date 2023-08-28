class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxi = values[n-1]-(n-1);
        int ans = INT_MIN;
        for(int i = n-2;i>=0;i--){
            ans = max(ans,values[i]+i+maxi);
            maxi = max(maxi,values[i]-i);
        }
        return ans;
    }
};