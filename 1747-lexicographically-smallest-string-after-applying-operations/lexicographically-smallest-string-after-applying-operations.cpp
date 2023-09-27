class Solution {
public:
    int a,b;
    void o1(string& s){
        for(int i = 0;i<s.length();i++){
            if(i&1) s[i] = (((s[i]-'0') + a )%10 + '0');
        }
    }
    void o2(string& s){
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());
    }
    string findLexSmallestString(string s, int A, int B) {
        queue<string> q;
        a = A;
        b = B;
        q.push(s);
        set<string> vis;
        vis.insert(s);
        while(!q.empty()){
            string temp  = q.front();
            q.pop();
            string t1 = temp,t2 = temp;
            o1(t1);
            o2(t2);
            if(vis.find(t1)==vis.end()){
                vis.insert(t1);
                q.push(t1);
            }
            if(vis.find(t2)==vis.end()){
                vis.insert(t2);
                q.push(t2);
            }
        }
        return *(vis.begin());

    }
};