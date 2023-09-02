class Solution {
public:
    int n;
    int m;
    bool isValid(int mid,vector<int>& tasks,vector<int>& workers,int pills,int strength){
        int cnt = 0;
        bool flag = true;
        multiset<int> st(workers.begin(),workers.end());
        for(int i = mid-1;i>=0;i--){
            auto it  = prev(st.end());
            if(tasks[i]<=*it) st.erase(it);
            else{
                auto it = st.lower_bound(tasks[i]-strength);
                if(it!=st.end()){
                    cnt++;
                    st.erase(it);
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(cnt>pills){
                flag = false;
                break;
            }
        }
        return flag;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        n = tasks.size();
        m = workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int start  = 0;
        int end  = min(n,m);
        int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(mid,tasks,workers,pills,strength)){
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return ans;
    }
};