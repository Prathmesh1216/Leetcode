class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        for(int i = 0;i<capacity.size();i++){
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        int ans = 0;
        for(int i = 0;i<capacity.size();i++){
            if(capacity[i]<=ar){
                ans++;
                ar-=capacity[i];
            }
        }
        return ans;
    }
};