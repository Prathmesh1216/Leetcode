class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        int sz = 1;
        int last = intervals[0][1];
        for(int i = 1;i<n;i++){
            if(intervals[i][0]>=last){
                sz++;
                last = intervals[i][1];
            }
            else continue;
        }
        return n-sz;

    }
};