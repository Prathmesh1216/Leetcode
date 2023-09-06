class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int ans = 0;
        
        int a = 1000;
        while(a--){
            bool flag = false;
            for(int i = 0;i<s.length()-1;i++){
                if(s[i]=='0' && s[i+1]=='1'){
                    swap(s[i],s[i+1]);
                    i++;
                    flag = true;
                }
            }
            if(!flag) return ans;
            ans++;
        }
        return s.length();
    }
};