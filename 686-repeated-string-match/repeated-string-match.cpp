class Solution {
public:
    bool isValid(string& a,string& b,int mid){
        string na = "";
        while(mid--) na += a;
       // cout << na << endl;
        if(na.find(b)!=string::npos) return true;
     //   if(j==b.length()) return true;
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int start = 1;
        int end = b.length()/a.length() + 2;
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(a,b,mid)){
                ans = mid ;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        
        return ans;
    }
};