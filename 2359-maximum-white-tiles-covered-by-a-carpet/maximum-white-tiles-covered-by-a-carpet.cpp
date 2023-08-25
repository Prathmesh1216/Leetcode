class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int l) {
        sort(tiles.begin(),tiles.end());
        int i = 0;
        int j = 0;
        int ans = 0;
        int lc = 0;
        while(j<tiles.size() && ans<l){
            if(tiles[i][0] + l>tiles[j][1]){
                 lc += (tiles[j][1]-tiles[j][0]+1);
                 ans = max(ans,lc);
                 j++;
            }
            else{
                int p = max(0,tiles[i][0]+l-tiles[j][0]);
                ans = max(ans,lc+p);
                lc -= (tiles[i][1]-tiles[i][0]+1);
                i++;
            }

  
        }
        return ans;
    }
};