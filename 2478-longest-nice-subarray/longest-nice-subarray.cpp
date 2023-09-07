class Solution {
public:
    bool isValid(vector<int>& v){
        for(int i = 0;i<30;i++){
            if(v[i]>1) return false;
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int oc = 0;
        int l = 0;
        int j = 0;
        vector<int> v(30);
        int ans = 1;
        int n = nums.size();
        while(j<n){
            for(int i = 0;i<30;i++){
                if(nums[j]&(1<<i)) v[i]++;
            }
            while(!isValid(v)){
                for(int i = 0;i<30;i++){
                    if(nums[l]&(1<<i)) v[i]--;
                }
                l++;
            }
            ans = max(ans,(j-l+1));
            j++;

        }
        return ans;
    }
};