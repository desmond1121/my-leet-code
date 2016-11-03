/**
 * Url: https://leetcode.com/problems/reverse-string/
 */
#include <iostream>

using namespace std;

class Solution {
public: 

    string reverseString(string s) {
        size_t length = s.length();
        char* res = new char[length];
        int halfLength = (int) (length / 2);
        for(int i = length - 1; i >= halfLength; i--) {
            res[length - 1 - i] = s[i];
            res[i] = s[length - 1 - i];
        }
        return string(res, length);
    }

};

int main () {
    Solution mSolution = Solution::Solution();
    cout << mSolution.reverseString("hello");
  return 0;
}

