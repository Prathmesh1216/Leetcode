class Solution {
public:
 int minSubarray(vector<int>& nums, int p) {
    long long sum = accumulate(nums.begin(),nums.end(),(long long)0);
    int r=sum%p;
    if(r==0) return 0;
    int ans = nums.size();
    unordered_map<int,int> m;
    sum=0;
    for(int i=0;i<nums.size() ;i++){
        sum+=nums[i];
        int k=sum%p;
        if(k==r) ans=min(ans,i+1);
        if(m.find(k-r)!=m.end())  ans =min(ans,i-m[k-r]);
        if(m.find(k-r+p)!=m.end()) ans =min(ans,i-m[p+k-r]);
        m[k]=i;            
    }
        if(ans>=nums.size()) return -1;
        return ans;
    }
};