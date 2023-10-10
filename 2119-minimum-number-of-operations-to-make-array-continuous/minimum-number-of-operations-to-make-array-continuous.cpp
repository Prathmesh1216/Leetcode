class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> nonrep;
        int n=nums.size();
        nonrep.push_back(nums[0]);
          
        for(int i=1;i<n;i++){
              if(nums[i]!=nums[i-1] ) nonrep.push_back(nums[i]);
        }
         int ans=n-1;
         int m=nonrep.size();
         for(int i=0;i<m;i++){
             int mini=nonrep[i];
             int maxi=n-1+mini;
             int it=upper_bound(nonrep.begin()+i,nonrep.end(),maxi)-nonrep.begin();
            //  cout<<it<<" ";
             ans=min(ans,n-it+i);

         }
        return ans;
    }
};