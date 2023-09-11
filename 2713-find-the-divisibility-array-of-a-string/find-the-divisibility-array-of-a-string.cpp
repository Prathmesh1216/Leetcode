class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.length();
        vector<int> ans(n);
        long long  sum = 0;
        for(int i = 0;i<n;i++){
            sum*= 10;
            sum += (word[i]-'0');
            sum = sum%m;
            if(sum==0) ans[i] = 1;
        }
        return ans;
    }
};