class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long int ans=0;
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
            int maxi=nums[i];
            int mini=nums[i];
            for (int j=i+1;j<n;j++)
            {
                if (nums[j]>maxi)
                    maxi=nums[j];
                if (nums[j]<mini)
                    mini=nums[j];
                ans+=(maxi-mini);
 
            }
        }
        return ans;
    }
};