class Solution {
public:
    string reverseParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int> st;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                reverse(s.begin()+st.top(),s.begin()+i);
                st.pop();
            }
        }
        string ans = "";
        for(auto it: s){
            if(it!='(' && it!=')') ans += it;
        }
        return ans;

    }
};