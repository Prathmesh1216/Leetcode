class Solution {
public:
    bool  isValid(long long mid,int n,vector<int>& batteries){
        int cnt = 0;
        long long csum = 0;
        for(auto& it : batteries){
            csum += it;
            if(csum>=mid){
                csum -= mid;
                cnt++;
            }
        }
        return cnt>=n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        long long start = 0;
        long long end =  accumulate(batteries.begin(),batteries.end(),0ll)/n;
        long long ans = -1;
        while(start<=end){
            long long mid = start + (end-start)/2;
            if(isValid(mid,n,batteries)){
                ans = mid;
                start = mid + 1;
            }
            else end = mid -1 ;
        }
        return ans;
    }
};