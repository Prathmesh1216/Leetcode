class Solution {
public:
    int wateringPlants(vector<int>& plants, int cp) {
        int a = cp;
        int n = plants.size();
        int steps = 0;
        for(int i = 0;i<plants.size()-1;i++){
            a-=plants[i];
            if(a<plants[i+1]){
                steps+= 2*(i+1);
                a = cp;
            }
            steps++;
        }
        return steps+1;
    }
};