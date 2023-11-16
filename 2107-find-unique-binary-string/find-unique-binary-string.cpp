class Solution {
public:
    string ans;
    int n;
    void solve(string& temp,set<string>& st){
        if(temp.length()==n){
            if(st.count(temp)) return;
            ans = temp;
            return;
        }
        temp.push_back('1');
        solve(temp,st);
        temp.pop_back();
        temp.push_back('0');
        solve(temp,st);
        return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st(nums.begin(),nums.end());
        n = nums[0].length();
        ans  = "";
        for(int i = 0;i<n;i++) ans += '0';
        string temp = "";
        solve(temp,st);
        return ans;
    }
};