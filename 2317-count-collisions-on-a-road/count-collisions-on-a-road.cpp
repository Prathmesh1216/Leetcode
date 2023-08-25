class Solution {
public:
    int countCollisions(string directions) {
        stack<char> s;
        int ans = 0;
        for(auto it : directions){
            if(it=='R'){
                s.push(it);
            }
            else if(it=='L'){
                bool flag = false;
                if(s.size()>0 && s.top()=='R'){
                    ans+= 2;
                    flag = true;
                    s.pop();
                }
                else if(s.size()>0 && s.top()=='S'){
                    ans += 1;
                     flag = true;
                }
                while(s.size()>0 && s.top()=='R'){
                    s.pop();
                    ans++;
                     flag = true;
                }
                if(flag) s.push('S');
            }
            else if(it=='S'){
                while(s.size()>0 && s.top()=='R'){
                    ans += 1;
                    s.pop();
                }
                s.push('S');
            }
        }
        return ans;
    }
};