class Solution {
public:
    int check(int n){
        vector<int> v(10);
        while(n){
            v[n%10]++;
            n/=10;
        }
        for(int i = 0;i<=9;i++) if(v[i] && v[i]!=i) return false;
        return true;
    }
    int nextBeautifulNumber(int n) {
        n++;
        while(1){
          if(check(n)) return n;
          n++;
        }
      return -1;

    }
};