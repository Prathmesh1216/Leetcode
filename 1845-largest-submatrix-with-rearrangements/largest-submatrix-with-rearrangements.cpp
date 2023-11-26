class Solution {
public:
    int lo(vector<int>& v){
        int start = 0;
        int end = v.size() - 1;
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(v[mid]==1){
                start = mid + 1;
                ans = mid;
            }
            else end = mid - 1;
        }
        return ans;
    }
    vector<int> nsr(vector<int>& v){
        stack<int> st;
        int n = v.size();
        vector<int> ans(n);
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && v[st.top()]>=v[i]) st.pop();
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nsl(vector<int>& v){
        int n = v.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            while(!st.empty() && v[st.top()]>=v[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j]!=0) matrix[i][j] += matrix[i-1][j];
            }
        }
        int ans = 0;
        for(auto& it : matrix){
            sort(it.rbegin(),it.rend());
            int t = 123456789;
            for(int j = 0;j<m;j++){
                if(it[j]==0) continue;
                t = min(t,it[j]);
                int area = (j+1)*t;
                ans = max(ans,area);
            }
        }
        return ans;
    }
};