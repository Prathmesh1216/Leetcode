class Solution {
public:
    vector<int> getRow(int ri) {
        vector<int> v;
        v = {1};
        for(int i = 1;i<=ri;i++){
            vector<int> temp = {1};
            for(int j = 0;j<v.size()-1;j++){
                temp.push_back(v[j]+v[j+1]);
            }
            temp.push_back(1);
            v = temp;
        }
        return v;
    }
};