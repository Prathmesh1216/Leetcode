class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        char last = 'h';
        while(a>0 && b>0){
            if(a>b && a>=2){
                ans += ("aab");
                last = 'b';
                a-=2;
                b--;
            }
            else if(b>a && b>=2){
                last = 'a';
                ans += "bba";
                b-=2;
                a--;
            }
            if(a==b){
                if(a>=2 && (last=='b'||last=='h')) ans+="aabb",a-=2,b-=2;
                else if(a>=2 && (last=='a'||last=='h')) ans+="bbaa",a-=2,b-=2;

                else if(a==1){
                    if(last=='b') ans+="ab",a--,b--;
                    else if(last=='a') ans+="ba",a--,b--;
                    else ans +="ab",a--,b--;
                }
            }


        }
        if(a==2) ans += "aa";
        if(a==1) ans+= "a";
        if(b==2) ans+= "bb";
        if(b==1) ans+= "b";
        return ans;
    }
};