/**
 * Url: https://leetcode.com/problems/add-strings/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {}

    string addStrings(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();

        int maxLength = 0;

        if(l1 > l2) {
            maxLength = l1;
        } else {
            maxLength = l2;
        }

        char* result = new char[maxLength + 1];
        int length = 0;
        int carry = 0;
        string::reverse_iterator it1 = num1.rbegin();
        string::reverse_iterator it2 = num2.rbegin();

        while(!(it1 == num1.rend() && it2 == num2.rend())) {
            int dig1;
            if(it1 == num1.rend()) {
                dig1 = 0;
            } else {
                dig1 = *it1 - '0';
            }
            int dig2;
            if(it2 == num2.rend()) {
                dig2 = 0;
            } else {
                dig2 = *it2 - '0';
            }

            int t = dig1 + dig2 + carry;
            if(t >= 10) {
                result[maxLength - length] = t % 10 + '0';
                carry = 1;
            } else {
                result[maxLength - length] = t + '0';
                carry = 0;
            }

            length++;
            if(it1 != num1.rend()) {
                it1++;
            }
            if(it2 != num2.rend()) {
                it2++;
            }
        }

        if(carry > 0) {
            result[0] = '1';
            length++;
        } else {
            result++;
        }

        return string(result, length);
    }
};

int main() {
    Solution s = Solution::Solution();
    cout << s.addStrings("0", "0") << endl;
}
