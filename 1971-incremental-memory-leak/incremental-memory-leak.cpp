class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        int i = 1;
        while(1){
            if(m1<i && m2<i) break;
            if(m1>=m2){
                m1-=i;
            }
            else m2-=i;
            i++;
        }
        return {i,m1,m2};
    }
};