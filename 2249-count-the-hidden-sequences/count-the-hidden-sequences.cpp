class Solution {
public:
    bool isValid(long long mid,vector<int>& diff,int lower){
        int lowest = 123456789;
        for(auto& it : diff){
            mid += it;
            if(mid<lower) return false;
        }
        return true;
    }
    bool isValid1(long long mid,vector<int>& diff,int upper){
        for(auto& it : diff){
            mid += it;
            if(mid>upper) return false;
        }
        return true;
    }
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int mini = 123456789;
        int maxi = -123456789;
        int start = lower;
        int end = upper;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(mid,differences,lower)){
                mini = mid;
                end = mid -1;
            }
            else start = mid + 1;
        }
        start = lower;
        end = upper;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid1(mid,differences,upper)){
                maxi = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        if(maxi<mini) return 0;
        return maxi - mini+1;

    }
};