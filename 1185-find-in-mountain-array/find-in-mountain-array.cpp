/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int start = 0;
        int end = n-1;
        int peak = -1;
        cout << start << "->" << end << endl;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(mid==0){
                start = mid + 1;
                continue;
            }
            if(mid==n-1){
                end = mid - 1;
                continue;
            }
            int a = mountainArr.get(mid);
            int b = mountainArr.get(mid+1);
            int c = mountainArr.get(mid-1);
            if(a>b && a>c){
                peak = mid;
                break;
            }
            else if(a>b){
                end = mid - 1;
            }
            else start = mid + 1;
        }
        cout << peak << endl;
        start = 0;
        end = peak;
        while(start<=end){
            int mid = start + (end-start)/2;
            int a = mountainArr.get(mid);
            if(a==target) return mid;
            else if(a<target){
                start = mid + 1;
            }
            else end = mid - 1;
        }
        start = peak+1;
        end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            int a = mountainArr.get(mid);
            if(a==target) return mid;
            else if(a<target){
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return -1;
    }
};