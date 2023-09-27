class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xr = 0;
        for(int i = 0;i<arr2.size();i++){
            xr ^= arr2[i];
        }
        for(int i = 0;i<arr1.size();i++){
            arr1[i] &= xr;
        }
        for(int i = 1;i<arr1.size();i++){
            arr1[i] ^= arr1[i-1];
        }
        return arr1[arr1.size()-1];
    }
};