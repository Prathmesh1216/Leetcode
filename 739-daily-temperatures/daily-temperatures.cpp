class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ans;
        int n = temperatures.size();
        for(int i = n-1;i>=0;i--){
            while(s.size()>0 && temperatures[s.top()]<=temperatures[i]) s.pop();
            if(s.empty()) ans.push_back(0);
            else ans.push_back(s.top()-i);
            s.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};