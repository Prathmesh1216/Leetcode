class Solution {
public:
    pair<int,int> decode(string& s){
        int a = 0, b = 0;
        int i = 0;
        bool neg = false;
        if(s[i]=='-') neg = true;
        if(neg) i++;
        while(s[i]!='+'){
            a = a*10 + (s[i]-'0');
            i++;
        }
        if(neg) a = -a;
        i++;
        neg = false;
        if(s[i]=='-') neg = true;
        if(neg) i++;
        while(i<s.length()-1){
            b = b*10 + (s[i]-'0');
            i++;
        }
        if(neg) b = -b;
        return make_pair(a,b);

    }
    string complexNumberMultiply(string num1, string num2) {
        pair<int,int> n1 = decode(num1), n2  = decode(num2);
        int r = n1.first*n2.first - n1.second*n2.second;
        int i = n1.first*n2.second + n2.first*n1.second;
        string ans = to_string(r) + "+" + to_string(i) + "i";
        return ans;
    }
};