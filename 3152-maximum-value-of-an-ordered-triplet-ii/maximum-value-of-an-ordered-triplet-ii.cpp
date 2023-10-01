class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
         int n=nums.size();
       vector<long long> maxi(n);
       maxi[0]=nums[0];
       for(int i=1;i<n;i++){
           maxi[i]=max(maxi[i-1],nums[i]*1LL);
       }
     priority_queue<long long> q;
     q.push(nums[n-1]);
     long long res=0;
        for(int i=n-2;i>=1;i--){
            long long a=maxi[i-1];
            long long c=q.top();
            res=max(res,(a-nums[i]*1LL)*c);
            q.push(nums[i]);



        }
     return res;   
       
    }
};