class Solution {
public:
    vector<int> nsl(vector<int>& arr){
        stack<int> s;
        vector<int> ans;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            if(s.empty()) ans.push_back(-1);
            else if(s.size()>0 && arr[s.top()]<=arr[i]) ans.push_back(s.top());
            else if(s.size()>0 && arr[s.top()]>arr[i]){
                while(s.size()>0 && arr[s.top()]>arr[i]){
                    s.pop();
                }
                if(s.empty()) ans.push_back(-1);
                else ans.push_back(s.top());
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> nsr(vector<int>& arr){
        stack<int> s;
        vector<int> ans;
        int n = arr.size();
        for(int i = n-1;i>=0;i--){
            if(s.empty()) ans.push_back(n);
            else if(s.size()>0 && arr[s.top()]<arr[i]){
                ans.push_back(s.top());
            }
            else if(s.size()>0 && arr[s.top()]>=arr[i]){
                while(s.size()>0 && arr[s.top()]>=arr[i]){
                    s.pop();
                }
                if(s.size()==0) ans.push_back(n);
                else ans.push_back(s.top());
            }
            s.push(i);

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> li = nsl(arr);
        vector<int> ri = nsr(arr);
        long long ans = 0;
        int mod = 1e9+7;
        for(int i = 0;i<arr.size();i++){
            long long b = (i-li[i])*(ri[i]-i);
            long long a = arr[i]*b;
            ans = (ans+a)%mod;
        }
        return ans%mod;
    }
};