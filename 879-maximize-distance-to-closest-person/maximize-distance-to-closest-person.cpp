class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> v(n);
        int left = -123456789;
        for(int i = 0;i<seats.size();i++){
            if(seats[i]==1){
                left = i;
            }
            else v[i] = i - left;
        }
        int right = 123456789;
        int ans = 0;
        for(int i = n-1;i>=0;i--){
            if(seats[i]==1) right = i;
            else v[i] = min(v[i],abs(right-i));
        }
        for(int i = 0;i<n;i++){
            if(!seats[i]) ans = max(ans,v[i]);
        }
        return ans;
    }
};