class DSU{
public:
    vector<int> par, size;
    DSU(int n)
    {
        par.resize(n+1);
        iota(par.begin(), par.end(), 0);
        size.resize(n+1, 1);
    }
    int findPar(int node)
    {
        if(par[node]==node) return node;
        return par[node] = findPar(par[node]);
    }
    void Union(int x, int y)
    {
        int p1 = findPar(x), p2 = findPar(y);
        if(p1==p2) return;
        if(size[p1]<=size[p2])
        {
            par[p1] = p2;
            size[p2] += size[p1];
        }
        else{
            par[p2] = p1;
            size[p1] += size[p2];
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        int n = s.size();
        DSU ds(n);
        for(auto pr: pairs)
        {
            ds.Union(pr[0], pr[1]);
        }
        unordered_map<int, string> chars;
        for(int i=0;i<n;i++)
        {
            chars[ds.findPar(i)].push_back(s[i]);
        }
        for(auto &[p, s]: chars) sort(s.begin(), s.end());
        vector<int> pointers(n);
        string ans;
        for(int i=0;i<n;i++)
        {
            int p = ds.findPar(i);
            ans.push_back(chars[p][pointers[p]++]);
        }
        return ans;
    }
};