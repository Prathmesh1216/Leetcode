class Solution {
public:
    int minimumRefill(vector<int>& plants, int ca, int cb) {
        int a = ca;
        int b = cb;
        int n = plants.size();
        int cnt = 0;
        int i = 0;
        int j = plants.size()-1;
        while(i<j){
            if(a<plants[i]){
                cnt++;
                a = ca;
            }
            if(b<plants[j]){
                cnt++;
                b = cb;
            }
            a-=plants[i];
            b-=plants[j];
            i++;
            j--;
        }
        if(!(n&1)) return cnt;
        if(max(a,b)>=plants[i]) return cnt;
        return cnt+1;
    }
};