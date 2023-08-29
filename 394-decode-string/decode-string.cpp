class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<char> st;
        stack<int> cnt;
        stack<string> tp;
        for(int i = 0;i<n;i++){
            if(i!=0 && isdigit(s[i]) && isdigit(s[i-1])){
               int num = 10*cnt.top()+s[i]-'0';
               cnt.pop();
               cnt.push(num);
            } 
            else if(isdigit(s[i])) cnt.push(s[i]-'0');
            else if(s[i]==']'){
                string temp = "";
                while(st.top()!='['){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                int n = cnt.top();
                cnt.pop();
                reverse(temp.begin(),temp.end());
                while(n--){
                    for(auto it : temp){
                    st.push(it);
                }
                }
            }
            else st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        while(!tp.empty()){
            ans+=tp.top();
            tp.pop();
        }
      reverse(ans.begin(),ans.end());
        return ans;

    }
};