class Solution {
public:
    int poorPigs(int b, int mtd, int mtt) {
        int rounds = mtt/mtd + 1;
        int start = 0;
        int end = 50;
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(pow(rounds,mid)>=b){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;

    }
};