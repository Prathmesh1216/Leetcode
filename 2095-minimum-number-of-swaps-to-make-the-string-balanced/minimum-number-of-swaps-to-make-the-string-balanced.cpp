class Solution {
public:
    int minSwaps(string s){
        int n  = s.length();
        int i = 0;
        int j = s.length()-1;
        int o = 0;
        int c = 0;
        int ans = 0;
        while(i<j){
            if(s[i]=='[') o++;
            else  c++;
            if(c>o){
                while(s[j]!='[') j--;
             //   swap(s[i],s[j]);
                o++;
                c--;
                ans++;
                j--;
            }
            i++;

        }
        return ans;
    }
};