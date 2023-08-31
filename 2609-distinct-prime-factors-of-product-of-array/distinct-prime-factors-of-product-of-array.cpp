class Solution {
public:
    set<int> st;
    void solve(int n){
        int a = sqrt(n);
        for(int i = 2;i<=a;i++){
            bool flag = false;
            while(n%i==0){
                flag = true;
                n /= i;
            }
            if(flag) st.insert(i);
        }
        if(n>1){
            st.insert(n);
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        for(auto it : nums) solve(it);
        return st.size();
    }
};