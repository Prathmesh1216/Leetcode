class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(k);
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            v[(nums[i]%k+k)%k]++;  
        }
        for(int i = 0;i<k;i++){
            if(i==0 && v[i]&1) return false;
            else if(i!=0){
                if(v[i]!=v[k-i]) return false;
            }
        }
        return true;


    }
};