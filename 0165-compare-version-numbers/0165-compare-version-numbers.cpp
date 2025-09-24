class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        int i = 0, j = 0;

        while(i < n || j < m) {
            int num1 = 0;
            int num2 = 0;

            // Get next number from version1
            while(i < n && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            // Get next number from version2
            while(j < m && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            // Compare the numbers
            if(num1 > num2) return 1;
            if(num1 < num2) return -1;

            i++; // skip '.' if any
            j++;
        }

        return 0; // all parts equal
    }
};
