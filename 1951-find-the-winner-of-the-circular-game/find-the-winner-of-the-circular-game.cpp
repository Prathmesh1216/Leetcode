class Solution {
public:
    int findTheWinner(int n, int k) {
        std::ios::sync_with_stdio(false);
        queue<int> q;
        for(int i = 1;i<=n;i++) q.push(i);
        while(q.size()>1){
            int a = k-1;
            while(a--){
                int b = q.front();
                q.pop();
                q.push(b);
            }
            q.pop();
        }
        return q.front();
    }
};