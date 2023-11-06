class Solution {
public:
    int digits(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n/=10;
        }
        return cnt;
    }
    int compress(vector<char>& chars) {
        if(chars.size()==1){
            return 1;
        }
        char last = chars[0];
        int cl  =1;
        int i = 1;
        vector<char> v;
        while(i<chars.size()){
            while(i<chars.size() && chars[i]==last){
                i++;
                cl++;
            }
            if(cl==1){
                v.push_back(last);
            }
            else if(cl>1){
                v.push_back(last);
                string t = to_string(cl);
                for(auto& it : t) v.push_back(it);
            }
            if(i<chars.size()){
                last = chars[i],cl  =1;
                if(i==chars.size()-1) v.push_back(last); 
            } 
            i++;
        }
        chars = v;
        int ans = v.size();
        return ans;
    }
};