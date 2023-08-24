class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> count(n);
        for(int i = 0;i<n;i++){
            for(auto iit : bank[i]){
                if(iit=='1') count[i]++;
            }
        }
        int last = count[0];
        int ans = 0;
        for(int i = 1;i<n;i++){
            if(count[i]){
                ans += count[i]*last;
                last = count[i];
            }
        }
        return ans;
    }
};