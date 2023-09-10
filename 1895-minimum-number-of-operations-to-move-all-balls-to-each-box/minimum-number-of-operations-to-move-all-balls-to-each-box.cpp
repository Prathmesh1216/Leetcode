class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n);
        //ps[0] = 0;
        for(int i = 0;i<n;i++){
            int cnt = 0;
            int a = 0;int b = 0;
            for(int j = 0;j<i;j++){
                if(boxes[j]=='1') cnt++;
                a += cnt;
            }
            cnt = 0;
            for(int j = n-1;j>=i+1;j--){
                if(boxes[j]=='1') cnt++;
                a += cnt;
            }
            ans[i] = a + b;
        }
        return ans;
    }
};