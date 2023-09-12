class Solution {
public:
    set<int> st;
    int maxCount(vector<int>& banned, int n, int maxSum) {
        for(auto& it : banned) st.insert(it);
        int sum = 0;
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            if(st.find(i)==st.end() && sum+i<=maxSum){
                sum += i;
                cnt++;
            }
        }
        return cnt;
    }
};