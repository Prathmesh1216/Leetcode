class Solution {
public:
    int n;
    bool isValid(long long mid,vector<int>& jobs,vector<long long>& workers,int i,int k){
        if(i==n) return true;
        int t = jobs[i];
        for(int j = 0;j<k;j++){
            if(workers[j]+t<=mid){
                workers[j] += t;
                if(isValid(mid,jobs,workers,i+1,k)) return true;
                workers[j] -= t;
            }
            if(workers[j]==0) break;
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) { 
        n = jobs.size();
        long long start = *max_element(jobs.begin(),jobs.end());
        long long end = accumulate(jobs.begin(),jobs.end(),0*1LL);
        int ans = -1;
        while(start<=end){
            long long mid = start + (end-start)/2;
            vector<long long> workers(k);
            if(isValid(mid,jobs,workers,0,k)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};