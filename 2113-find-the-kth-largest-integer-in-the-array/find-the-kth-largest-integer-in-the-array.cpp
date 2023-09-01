class Solution {
public:
    static bool cmp(string& a,string& b){
        if(a.length()==b.length()){
            int i = 0;
            int j = 0;
            while(i<a.length() && a[i]==b[j]){
                i++;
                j++;
            }
            if(i==a.length()) return a>b;
            return a[i]>b[j];
        }
        return a.length()>b.length();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        return nums[k-1];
    }
};