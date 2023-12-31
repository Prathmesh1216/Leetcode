class Solution {
public:
    
    int longestSubstring(string s, int k) {
        if(s.size()==0 || k>s.size()) return 0;
        if(k<=1) return s.size();
        unordered_map<char,int> m;
        for(auto it:s) m[it]++;
        int i=0;
        while(i<s.size() && m[s[i]]>=k) i++;
        if(i==s.size()) return s.size();
        int left=longestSubstring(s.substr(0,i),k);
        int right=longestSubstring(s.substr(i+1),k);
        return max(left,right);
    }
};