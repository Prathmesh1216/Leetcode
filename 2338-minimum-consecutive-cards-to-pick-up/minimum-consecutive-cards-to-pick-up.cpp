class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int i = 0;
        int j = 0;
        int ans = 123456789;
        while(j<cards.size()){
            mp[cards[j]]++;
            while(mp.size()<j-i+1){
                ans = min(ans,j-i+1);
                mp[cards[i]]--;
                if(mp[cards[i]]==0) mp.erase(cards[i]);
                i++;
            }
            j++;
        }
        return (ans == 123456789)?-1:ans;
    }
};