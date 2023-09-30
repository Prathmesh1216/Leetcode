class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char,int> v;
        while(j<s.length()){
            v[s[j]]++;
            if(v[s[j]]>1){
                while(v[s[j]]>1){
                    v[s[i]]--;
                    if(v[s[i]]==0) v.erase(s[i]);
                    i++;
                }
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};