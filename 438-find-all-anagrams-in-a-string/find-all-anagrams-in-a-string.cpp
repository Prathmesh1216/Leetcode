class Solution {
public:
bool isanagram(vector<int>& v,vector<int> perm){
	for(int i = 0;i<26;i++){
		if(v[i]!=perm[i]) return false;
	}
	return true;
}
    vector<int> findAnagrams(string s, string p) {
	vector<int> v(26),perm(26);
	vector<int> ans;
	int i = 0;
	int j = 0;
	int n = s.length();
	int m = p.length();
	for(int i = 0;i<m;i++) perm[p[i]-'a']++;
	while(j<n){
		v[s[j]-'a']++;
		if(j-i+1==m){
			if(isanagram(v,perm)) ans.push_back(i);
			v[s[i]-'a']--;
			i++;
		}
		j++;
	}
	return ans;
    }
};