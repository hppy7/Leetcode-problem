class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long di=(num-3)/3;
        long long sum=3*di+3;
        if(sum==num)
        return {di,di+1,di+2};
    return {};
    }
};