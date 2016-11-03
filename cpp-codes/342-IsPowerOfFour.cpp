/**
 * Url: https://leetcode.com/problems/power-of-four/
 */

class Solution {
public:
    Solution() {}

    bool isPowerOfFour(int n) {
        if(num <= 0) {
            return false;
        }
        return (num & (num - 1)) == 0 && (num | 0x55555555) == 0x55555555;
    }
};
