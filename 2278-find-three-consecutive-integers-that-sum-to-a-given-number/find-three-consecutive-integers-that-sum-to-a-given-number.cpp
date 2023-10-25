class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long b = num/3;
        long long a = b-1,c = b+1;
        if(a+b+c==num) return {a,b,c};
        return {};
    }
};