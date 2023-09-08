class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
      //  if(k==1) return ans;
        int low = 1;
        int high = n;
        int idx = 0;
        while(low<=high){
            if(k>1){
                ans[idx] = (k--)%2!=0?low++:high--;
            }
            else ans[idx] = low++;
            idx++;
        } 
        return ans;
    }
};
// class Solution {
//     public int[] constructArray(int n, int k) {
//         int[] result =new int[n];
        
//         int high = n , low = 1;
//         int index = 0;
        
//         result[index++] = low++;
        
//         boolean isHigh = false;
        
//         while(k>1){
//             result[index++] = high--;
//             k--;
//             isHigh = true;
//             if(k>1){
//                 result[index++] = low++;
//                 k--;
//                 isHigh = false;
//             }
//         }
        
//         //increasing or decreasing
//         while(index<n){
//             if(isHigh){
//                 result[index++] = high--;
//             }
//             else{
//                 result[index++] = low++;
//             }
//         }
        
//         return result;
//     }
// }