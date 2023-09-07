class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int sum = 0;
        int i = 0;
        int j = 0;
        int n = s.length();
        while(j<n){
            sum += abs(s[j]-t[j]);
            while(sum>maxCost){
                sum-=abs(s[i]-t[i]);
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};