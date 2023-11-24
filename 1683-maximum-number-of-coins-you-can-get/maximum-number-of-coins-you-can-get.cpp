class Solution {
public:
    int maxCoins(vector<int>& piles) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(piles.begin(),piles.end());
        int n = piles.size()/3;
        if(n==1) return piles[1];
        int i = 3*n-2;
        int ans = 0;
        while(n>0 && i>=0){
            ans += piles[i];
            i-=2;
            n--;
        }
        return ans;
    }
};