class Solution {
public:
    int solve(int i,bool del,vector<int>& arr){
        if(i==arr.size()) return 0;
        if(del){
            return max({solve(i+1,!del,arr),arr[i]+solve(i+1,del,arr),arr[i]});
        }
        return max({arr[i],arr[i] + solve(i+1,del,arr),solve(i+1,!del,arr)});
    }
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return arr[0];
        int cneg = 0;
        for(int i = 0;i<n;i++) if(arr[i]<0) cneg++;
        if(cneg==n) return *max_element(arr.begin(),arr.end());
         vector<int> ps(n);
        vector<int> ss(n);
        ps[0] = (arr[0]>0)?arr[0]:0;
        ss[n-1] = (arr[n-1]>0)?arr[n-1]:0;
        for(int i = 1;i<n;i++){
            ps[i] = (ps[i-1]+arr[i]>0)?ps[i-1]+arr[i]:0;
        }
        for(int i = n-2;i>=0;i--){
            ss[i] = (ss[i+1]+arr[i]>0)?ss[i+1]+arr[i]:0;
        }
        int ans = -123456789;
        for(int i = 0;i<n;i++){
            if(i==0) ans =  max({ans,ss[i+1],arr[i]+ss[i+1]});
            else if(i==n-1) ans = max({ans,ps[i-1],arr[i]+ps[i-1]});
            else ans = max({ans,ps[i-1]+ss[i+1],arr[i]+ps[i-1]+ss[i+1]});
        }
        return ans;
    }
};