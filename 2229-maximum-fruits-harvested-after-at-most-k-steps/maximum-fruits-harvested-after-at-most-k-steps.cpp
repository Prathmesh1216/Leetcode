class Solution {
public:
    int steps(int i,int j,int sp){
        if(sp<=i) return j-sp;
        else if(sp>=j) return sp-i;
        return min(2*j-sp-i,sp-2*i+j);
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int i = 0;
        while(i<n && fruits[i][0]<startPos-k){
            i++;
        }
        int j = i;
        int ans = 0;
        int sum = 0;
        while(j<n && fruits[j][0]<=startPos+k){
            sum += fruits[j][1];
            while(i<=j && steps(fruits[i][0],fruits[j][0],startPos)>k){
                sum-=fruits[i][1];
                i++;
            }
            ans = max(ans,sum);
            j++;
        }
        return ans;
    }
};