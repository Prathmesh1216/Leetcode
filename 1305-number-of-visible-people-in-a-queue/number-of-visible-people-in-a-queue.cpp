class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans(n);
        stack<int>s;
       if(n==1){
           return ans;
       }
       for(int i=n-1;i>=0;i--){
           int cnt=1;
           while(!s.empty() && heights[i]>s.top()){
               s.pop();
               cnt++;
           }
           if(s.empty())cnt=cnt-1;
           ans[i]=cnt;
           s.push(heights[i]);
       }
       return ans;
    }
};