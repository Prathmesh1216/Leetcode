class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool flag = true;
        while(1){
            flag = true;
            for(int i = 1;i<nums.size()-1;i++){
            double avg = 1.0*(nums[i-1]+nums[i+1])/2;
          //  cout << avg << endl;
            if(avg==nums[i]){
                flag = false;
                swap(nums[i],nums[i-1]);
            } 
        }
            if(flag) return nums;
        }

        return nums;
    }
};