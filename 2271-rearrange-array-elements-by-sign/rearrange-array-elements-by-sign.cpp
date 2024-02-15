class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> q1;
        queue<int> q2;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for(auto& it : nums){
            if(it<0) q1.push(it);
            else q2.push(it);
        }
        int i = 0;
        while(!q1.empty() && !q2.empty()){
            nums[i] = q2.front();
            i++;
            nums[i] = q1.front();
            i++;
            q2.pop();
            q1.pop();
        }
        return nums;
    }
};