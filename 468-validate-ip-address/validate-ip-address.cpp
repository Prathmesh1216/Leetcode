class Solution {
public:
      bool ipv4(string& s){
    int n = s.length();
    int dc = 0;
    vector<string> v;
    string temp = "";
    for(int i = 0;i<s.length();i++){
      if(s[i]!='.' && !isdigit(s[i])) return false;
      if(s[i]=='.'){
        dc++;
        if(temp.size()==0 || temp.size()>3) return false;
        if(temp[0]=='0' && temp.size()!=1) return false;
        v.push_back(temp);
        temp = "";
      }
      else temp += s[i];
    }
    if(dc!=3) return false;
    if(temp.size()==0 || temp.size()>3) return false;
    if(temp[0]=='0' && temp.size()!=1) return false;
    v.push_back(temp);
    if(v.size()!=4) return false;
    for(auto& it : v){
      if(stoi(it)>255) return false;
      else if(it.length()>1 && stoi(it)==0) return false;
    }
    return true;
  }
  bool ipv6(string& s){
    int n = s.length();
    int dc = 0;
    vector<string> v;
    string temp = "";
    for(int i = 0;i<s.length();i++){
      if(s[i]!=':' && !(s[i]>='0'&&s[i]<='9') && !(s[i]>='a'&&s[i]<='f') && !(s[i]>='A'&&s[i]<='F')) return false;
      if(s[i]==':'){
        dc++;
        if(temp.size()==0 || temp.size()>4) return false;
        v.push_back(temp);
        temp = "";
      }
      else temp += s[i];
    }
    if(dc!=7) return false;
    if(temp.size()==0 || temp.size()>4) return false;
    v.push_back(temp);
    if(v.size()!=8) return false;
    return true;
  }
    string validIPAddress(string& s) {
        if(ipv4(s)) return "IPv4";
        else if(ipv6(s)) return "IPv6";
        return "Neither";
    }
};