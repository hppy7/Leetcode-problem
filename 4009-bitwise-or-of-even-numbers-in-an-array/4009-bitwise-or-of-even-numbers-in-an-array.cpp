class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int result = 0;              // store OR of even numbers
        for (int num : nums) {       // iterate through each element
            if (num % 2 == 0) {      // check if number is even
                result |= num;       // bitwise OR with result
            }
        }
        return result;               // if no even numbers, result stays 0
    }
};
