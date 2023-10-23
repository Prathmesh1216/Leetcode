class Solution {
public:
    int lb(int a,vector<int>& potions,long long success){
        int start = 0;
        int end = potions.size()-1;
        int ans = potions.size();
        while(start<=end){
            int mid = start + (end-start)/2;
            if(potions[mid]*1LL*a>=success) ans = mid,end = mid - 1;
            else start = mid + 1;
        }
        return potions.size()-ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        vector<int> pairs(n);
        for(int i = 0;i<n;i++){
            pairs[i] = lb(spells[i],potions,success);
        }
        return pairs;
    }
};