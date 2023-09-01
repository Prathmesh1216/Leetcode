class Solution {
public:
    int n;
    bool isValid(int mid,vector<int>& dist,double hour){
        int time = 0;
        for(int i = 0;i<dist.size()-1;i++){
            if(dist[i]%mid) time+=(dist[i]/mid+1);
            else time+= (dist[i]/mid);
        }
        double t = 1.0*dist[n-1]/mid;
        if(t+time<=hour) return true;
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start = 1;
        int end = 10000000;
        int ans = -1;
        n = dist.size();
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(mid,dist,hour)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};