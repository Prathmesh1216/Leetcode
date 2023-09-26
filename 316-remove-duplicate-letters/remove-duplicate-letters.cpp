class Solution {
public:
    string removeDuplicateLetters(string& s) {
        vector<int> li(26);
        vector<bool> vis(26);
        for(int i = 0;i<s.length();i++){
            li[s[i]-'a'] = i;
        }
        stack<char> st;
        for(int i = 0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
                vis[s[i]-'a'] = 1;
            }
            else if(!st.empty() && (s[i] - 'a') > (st.top() - 'a') && !vis[s[i]-'a']){
                st.push(s[i]);
                vis[s[i]-'a'] = 1;
            }
            else if(!vis[s[i]-'a']){
                while(!st.empty() && (st.top()-'a')>(s[i] - 'a') && li[st.top()-'a']>i ){
                    vis[st.top()-'a'] = 0;
                    st.pop();
                }
                st.push(s[i]);
                vis[s[i]-'a'] = 1;
            }
        }
        string ans = "";
        while(!st.empty()) ans += st.top(),st.pop();
        // cout << ans.size() << endl;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};