/**
 * Url: https://leetcode.com/problems/power-of-two/
 */
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {}

    bool isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }
        int m = n - 1;
        return (m & n) == 0;
    }
};

int main() {
    Solution s = Solution::Solution();
    cout << s.isPowerOfTwo(1) << endl;
    cout << s.isPowerOfTwo(4) << endl;
    cout << s.isPowerOfTwo(1024) << endl;
}
