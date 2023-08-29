class Solution {
public:
    // static bool cmp(vector<int>& a,vector<int>& b){
    //     if(a[0]==b[0]) return a[1]<b[1];
    //     return a[0]<b[0]
    // }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ans;
        for(int i = 0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end()); 
        for(int i = 0;i<n;i++){
            swap(tasks[i][0],tasks[i][1]);
            swap(tasks[i][1],tasks[i][2]);
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int i = 0;
        int time = tasks[0][2];
        while(i<n){
            if(pq.empty() && time<tasks[i][2]){
                time = tasks[i][2];
            }
            while(i<n && time>=tasks[i][2]){
                pq.push(tasks[i]);
                i++;
            }
            ans.push_back(pq.top()[1]);
            time+= pq.top()[0];
            pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        return ans;
    }
};