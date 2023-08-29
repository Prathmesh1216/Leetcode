class Solution {
public:
    int tt;
    bool isValid(long long mid,vector<int>& time){
        long long ans = 0;
        for(auto it : time){
            ans += (mid/it);
        }
      //  cout << mid << " " << ans << endl;
        if(ans>=tt) return true;
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        tt = totalTrips;
        long long start = 1;
        long long end = 100000000000000;
        long long ans = 0;
        while(start<=end){
            long long mid = start + (end-start)/2;
            if(isValid(mid,time)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};