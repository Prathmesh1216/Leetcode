class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.length();
        queue<pair<string,int>> q;
        q.push({s1,0});
        unordered_set<string> st;
        st.insert(s1);
        int ans = n;
        while(!q.empty()){
            string a = q.front().first;
            int k = q.front().second;
            q.pop();
            if(a==s2) return k;
            int i =0;
            while(a[i]==s2[i]) i++;
            for(int j = i;j<n;j++){
                if(a[j]==s2[i] && a[j]!=s2[j]){
                    swap(a[i],a[j]);
                    if(!st.count(a)){
                     q.push({a,k+1});
                     st.insert(a);
                    }
                    swap(a[i],a[j]);
                }
                
            }
        }
        return ans;
    }
};
// queue<pair<string, int>> q;
//         unordered_set<string> vis;
//         vis.insert(a);
//         q.push({a, 0});
//         int ans = 0, n = a.size();
//         while(!q.empty())
//         {
//             auto [cur, d] = q.front();
//             q.pop();
//             if(cur==b) return d;
//             int i = 0;
//             while(cur[i]==b[i]) i++;
//             for(int j=i;j<n;j++)
//             {
//                 if(cur[j]==b[i] && cur[j]!=b[j])
//                 {
//                     swap(cur[i], cur[j]);
//                     if(!vis.count(cur))
//                     {
//                         vis.insert(cur);
//                         q.push({cur, d+1});
//                     }
//                     swap(cur[i], cur[j]);
//                 }
//             }
//         }
//         return ans;//