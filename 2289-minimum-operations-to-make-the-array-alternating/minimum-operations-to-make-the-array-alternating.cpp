class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i = 0;i<nums.size();i++){
            if(i&1) mp2[nums[i]]++;
            else mp1[nums[i]]++;
        }
        int maxo = 0;
        int maxe = 0;
        int ans1 = 0;
        for(auto it : mp1){
            if(it.second>mp1[maxe]) maxe = it.first;
        }
        int n = nums.size();
        ans1+=((n+1)/2-mp1[maxe]);
        for(auto it : mp2){
            if(it.second>mp2[maxo] && it.first!=maxe) maxo= it.first;
        }
        ans1+= ((n)/2-mp2[maxo]);
        int ans2 = 0;
        maxo = 0;
        maxe = 0;
        for(auto it : mp2){
            if(it.second>mp2[maxo]) maxo= it.first;
        }
        ans2+= ((n)/2-mp2[maxo]);
        for(auto it : mp1){
            if(it.second>mp1[maxe] && it.first!=maxo) maxe= it.first;
        }
        ans2+=((n+1)/2-mp1[maxe]);
        return min(ans1,ans2);

    }
};