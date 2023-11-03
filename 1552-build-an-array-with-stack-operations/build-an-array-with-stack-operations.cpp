class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 1;
        int j = 0;
        while(j<target.size()){
            if(target[j]==i){
                ans.push_back("Push");
                i++;
                if(i>n) i = 1;
            }
            else if(i<target[j]){
                int c = 0;
                while(i<target[j]){
                    ans.push_back("Push");
                    c++;
                    i++;
                }
                while(c--) ans.push_back("Pop");
                ans.push_back("Push");
                i++;
            }
            j++;
        }
        return ans;
    }
};