class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i = 0;i<s.length();i++){
            if(!st.empty() && st.top().first==s[i]){
                int a = st.top().second;
                a++;
                st.pop();
                if(a>=k) a-=k;
                if(a) st.push({s[i],a});
            }
            else st.push({s[i],1});
        }
        string ans = "";
        while(!st.empty()){
            int a = st.top().second;
            char ch  = st.top().first;
            while(a--){
                ans += ch;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};