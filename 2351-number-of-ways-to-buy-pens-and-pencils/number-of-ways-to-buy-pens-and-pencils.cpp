class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int mp = total/cost1;
        long long ans = 0;
        for(int i = 0;i<=mp;i++){
            ans  += (total-cost1*1LL*i)/cost2 + 1;
        }
        return ans;
    }
};