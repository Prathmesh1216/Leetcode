class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> v(30);
        for(auto& it : candidates){
            for(int i = 0;i<30;i++){
                if(it&(1<<i)) v[i]++;
            }
        }
        int ans = 0;
        for(int i = 0;i<30;i++) ans = max(ans,v[i]);
        return ans;
    }
};