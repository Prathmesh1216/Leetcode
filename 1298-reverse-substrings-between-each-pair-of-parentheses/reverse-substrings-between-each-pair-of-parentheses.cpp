class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        vector<pair<int,int>> v;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                v.push_back({st.top(),i});
                st.pop();
            }
        }
        for(auto it : v){
            reverse(s.begin()+it.first,s.begin()+it.second);
        }
        string ans = "";
        for(auto it: s){
            if(it!='(' && it!=')') ans += it;
        }
        return ans;

    }
};