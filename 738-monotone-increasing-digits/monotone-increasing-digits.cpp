class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int i = 1;
        int n = s.length();
        while(i<n && s[i]>=s[i - 1]) i++;
        if(i==n) return N;
        while(i>0 && s[i-1]>s[i]){
            i--;
            s[i]--;
        }
        for(int j = i+1;j<n;j++)s[j] = '9';
        return stoi(s);
    }
};