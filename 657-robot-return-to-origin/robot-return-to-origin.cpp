class Solution {
public:
    bool judgeCircle(string moves) {
        int cu = 0,cr = 0,cd = 0,cl = 0;
        for(auto& it : moves){
            if(it=='U') cu++;
            else if(it=='R') cr++;
            else if(it=='L') cl++;
            else cd++;
        }
        return (cu==cd) && (cl==cr);
    }
};