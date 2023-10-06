class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(),1);
        for(int i = 0;i<l.size();i++){
            vector<int> temp(nums.begin()+l[i],nums.begin()+r[i]+1);
            // for(auto& it : temp) cout<<it <<" " ;
            // cout << endl;
            sort(temp.begin(),temp.end());
            int j = 0;
            if(temp.size()<=1){
                ans[i] = 0;
                continue;
            }

            while(j<temp.size()-1){
                if(temp[j]-temp[j+1]!=temp[0]-temp[1]){
                    ans[i] = 0;
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};