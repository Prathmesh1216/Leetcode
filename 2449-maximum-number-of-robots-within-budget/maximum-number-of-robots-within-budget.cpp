class Solution {
public:
    int n;
    long long b;
    bool solve(int mid,vector<int>& chargeTimes,vector<int>& runningCosts){
        int i = 0;
        int j = 0;
        long long sum = 0;
        list<int> q;
        int maxi = 0;
        while(j<n){
            sum += runningCosts[j];
            while(q.size()>0 && q.back()<chargeTimes[j]) q.pop_back();
            q.push_back(chargeTimes[j]);
    
        if(j-i+1==mid){
            maxi = q.front();
            if((maxi + mid*sum)<=b) return true;
            sum -= runningCosts[i];
            if(maxi==chargeTimes[i]) q.pop_front();
            i++;
        }
        j++;
        }
        return false;

    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        n = chargeTimes.size();
        b = budget;
        int ans = 0;
        int start = 1;
        int end = n;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(solve(mid,chargeTimes,runningCosts)){
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return ans;
    }
};