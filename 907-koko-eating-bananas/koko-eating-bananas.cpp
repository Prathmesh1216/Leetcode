class Solution {
public:
    #define ll long long
    bool isValid(ll mid,vector<int>& nums,int h){
        int cnt = 0;
        for(auto& it : nums){
            cnt += (it/mid + (it%mid!=0));
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ll start = 1;
        ll end = accumulate(piles.begin(),piles.end(),0ll);
    ll ans = -1;
        while(start<=end){
            ll mid = start + (end-start)/2;
            if(isValid(mid,piles,h)){
                ans = mid; end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};