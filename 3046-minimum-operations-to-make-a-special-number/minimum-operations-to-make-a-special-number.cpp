class Solution {
public:
    int minimumOperations(string nums) {
        int n = nums.length();
        int c0 = 0;
        int ans = n;
        for(auto it : nums) if(it=='0') c0++;
        if(c0==1) ans = n-1;
        for(int i = 0;i<n;i++){
            int a = (nums[i]-'0')*10;
            for(int j = i+1;j<n;j++){
                a += (nums[j]-'0');
                if(a==0 || a==25 || a==50 || a==75) ans = min(ans,n-i-2);
                a-=(nums[j]-'0');
            }
        }
        return ans;
    }
};