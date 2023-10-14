class Solution {
public:
    int wateringPlants(vector<int>& plants, int cp) {
        int a = cp;
        int sc = 0;
        for(int i = 0;i<plants.size()-1;i++){
            a-=plants[i];
            if(plants[i+1]>a){
                sc += 2*(i+1);
                a = cp;
            }
            sc++;
        }
        return sc+1;
    }
};