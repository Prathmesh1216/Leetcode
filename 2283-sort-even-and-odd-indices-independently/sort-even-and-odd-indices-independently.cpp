class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        for(int i = 0;i<nums.size();i++){
            if(i&1) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        sort(v1.rbegin(),v1.rend());
        sort(v2.begin(),v2.end());
        int i = 0;
        int j = 0;
        int k = 0;
        while(k<nums.size()){
            if(k&1){
                nums[k] = v1[i];
                k++;
                i++;
            }
            else{
                nums[k] = v2[j];
                k++;
                j++;
            }
        }
        return nums;
    }
};