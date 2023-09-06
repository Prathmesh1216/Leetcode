class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i = 0;i<s.length();i++){
            if(st.empty()){
                st.push({s[i],1});
                continue;
            }
            if(st.top().first==s[i]){
                if(st.top().second==k-1){
                    st.pop();
                }
                else{
                    int a = st.top().second;
                    st.pop();
                    st.push({s[i],a+1});
                }
            }
            else st.push({s[i],1});
        }
        string ans = "";
        cout << st.size();
        while(!st.empty()){
            int a = st.top().second;
            while(a--){
                ans += st.top().first;
            }
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};