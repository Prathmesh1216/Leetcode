class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int lw = arr[0];
        int mc = 0;
        for(int i = 1;i<arr.size();i++){
            if(arr[i]>lw){
                lw = arr[i];
                mc = 1;
            }
            else mc++;
            if(mc==k) return lw;
        }
        return lw;

    }
};