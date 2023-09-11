class FindSumPairs {
public:
    unordered_map<int,int> mp;
    vector<int> v1,v2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto it : nums2) mp[it]++;
        v1 = nums1;
        v2 = nums2;
    }
    
    void add(int index, int val) {
        mp[v2[index]]--;
        v2[index] += val;
        mp[v2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i = 0;i<v1.size();i++){
            ans += mp[tot-v1[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */