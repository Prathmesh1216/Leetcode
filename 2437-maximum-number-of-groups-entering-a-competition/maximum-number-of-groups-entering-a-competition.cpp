class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        int n = grades.size();
        int cnt = 0;
        int ls = grades[0]-1;
        int sz = 0;
        int i = 0;
        int j = 0;
        while(i<n){
            int tsum = 0;
            while(j<n && (tsum<=ls || (j-i)<=sz)){
                tsum += grades[j];
                j++;
            }
            if(tsum>ls && j-i>sz){
                cnt++;
                sz = j-i;
                ls = tsum;
                i = j;
            }
            else break;
        }
        return cnt;

    }
};