class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        vector<long long> ss(n);
        ss[n-1] = shifts[n-1];
        for(int i = n-2;i>=0;i--){
            ss[i] = (ss[i+1]+shifts[i])%26;
            cout << ss[i] << " ";
        }
        for(int i = 0;i<n;i++){
            s[i] = char('a'+ (s[i]-'a'+ss[i])%26);
        }
        return s;
    }
};