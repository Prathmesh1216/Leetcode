class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0,b = 0;
        int cnt = 0;
        for(int i = 0;i<colors.length();i++){
            if(colors[i]=='A'){
                cnt++;
            }
            else{
                if(cnt>=3) a+=(cnt-2);
                cnt = 0;
            }
        }
        if(cnt>=3) a+=(cnt-2);
        cnt = 0;
        for(int i = 0;i<colors.length();i++){
            if(colors[i]=='B'){
                cnt++;
            }
            else{
                if(cnt>=3) b+=(cnt-2);
                cnt = 0;
            }
        }
        if(cnt>=3) b+=(cnt-2);
       // cout << a<< " " << b << endl;
        return a>b;
    }
};