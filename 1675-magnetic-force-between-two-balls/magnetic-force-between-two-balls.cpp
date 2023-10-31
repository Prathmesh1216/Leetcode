class Solution {
public:
    bool isValid(int mid,vector<int>& position,int m){
        int cnt = 1;
        int last = position[0];
        for(int i = 1;i<position.size();i++){
            if(position[i]-last>=mid){
                cnt++;
                last = position[i];
            }
        }
        return cnt>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int start = 0;
        int end = position[n-1]-position[0];
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(mid,position,m)){
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return ans;
    }
};