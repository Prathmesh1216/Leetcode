class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(),answers.end());
        int ans = 0;
        int cnt = 1;
        int currans = 0;
        int n = answers.size();
        for(int i = 0;i<answers.size();i++){
            if(i+1==n || answers[i]!=answers[i+1]){
                int mod = cnt%(answers[i]+1);
                ans += (cnt/(answers[i]+1))*(answers[i]+1);
                if(mod) ans += (answers[i]+1);
               // cout << ans << endl;
                cnt = 0;
            }
           cnt++;
        }
      //  if(cnt<=answers[n-1]) ans = ans+answers[n-1]+1;
        return ans;
    }
};