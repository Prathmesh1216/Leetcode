class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
      //  vector<int> ps(n+1);
        vector<int> ss(n+1);
        ss[n] = 0;
        int cy = 0;
        for(int i = n-1;i>=0;i--){
            if(customers[i]=='Y') cy++;
            ss[i] = cy;
        }
        int cn = 0;
        for(int i = 1;i<n+1;i++){
            if(customers[i-1]=='N') cn++;
            ss[i]+=cn;
        }
        int ans = 0;
        for(int i = 0;i<n+1;i++){
            if(ss[i]<ss[ans]) ans = i;
        }
        return ans;
    }
};