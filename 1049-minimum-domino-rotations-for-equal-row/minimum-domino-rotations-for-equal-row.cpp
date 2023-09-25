class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = 123456789;
        for(int i = 1;i<=6;i++){
            int cnt = 0;
            bool flag = true;
            for(int j = 0;j<tops.size();j++){
                if(tops[j]!=i && bottoms[j]!=i){
                    flag = false;
                    break;
                }
                else if(tops[j]!=i && bottoms[j]==i){
                    cnt++;
                }

            }
            if(flag) ans = min(ans,cnt);
        }
        for(int i = 1;i<=6;i++){
            int cnt = 0;
            bool flag = true;
            for(int j = 0;j<tops.size();j++){
                if(tops[j]!=i && bottoms[j]!=i){
                    flag = false;
                    break;
                }
                else if(tops[j]==i && bottoms[j]!=i){
                    cnt++;
                }

            }
            if(flag) ans = min(ans,cnt);
        }
        return (ans==123456789)?-1:ans;
    }
};