class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto it : words) mp[it]++;
        // for(auto& it : mp){
        //     cout << it.first << " : " << it.second << endl;
        // }
        int ml = 0;
        int cl = 0;
        for(auto& it : words){
            if(it[0] == it[1]){
                if(mp[it]>1){
                    if(mp[it]&1) ml+= (mp[it]-1), mp[it] = 1;
                    else ml += mp[it],mp[it] = 0;
                } 
                continue;
            }
            string temp = it;
            reverse(temp.begin(),temp.end());
            if(mp.find(temp)!=mp.end()){
                ml += 2*min(mp[it],mp[temp]);
                mp.erase(it);
            }
        }
        int c = 0;
        for(auto& it : mp){
            if(it.first[0] == it.first[1]){
                c = max(c,mp[it.first]);
            }
        }
        return 2*(ml+c);
    }
};