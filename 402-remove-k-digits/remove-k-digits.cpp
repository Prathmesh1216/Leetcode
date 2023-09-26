class Solution {
public:
    string removeKdigits(string num, int g) {
        stack<char> st;
        int n=num.length();
        int k = n - g;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.size()+(n-i)>k && st.top()>num[i]){
                st.pop();

            }
            if(st.size()<k) st.push(num[i]);
        }
       string ans = "";
       if(st.empty()) return "0";
       while(!st.empty()){
           ans += st.top();
           st.pop();
       } 
       while(ans.size()>0 && ans[ans.size()-1] == '0') ans.erase(ans.size()-1);
       if(ans.size()==0) return "0";
       reverse(ans.begin(),ans.end());

       return ans;
    }
};