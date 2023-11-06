class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        int n = t.size();
        vector<int> ngr(n);
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && t[st.top()]<=t[i]) st.pop();
            if(st.empty()) ngr[i] = 0;
            else ngr[i] = st.top() - i;
            st.push(i);
        }
        return ngr;
    }
};