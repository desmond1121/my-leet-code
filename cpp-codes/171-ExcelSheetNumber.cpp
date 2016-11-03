/**
 * Url: https://leetcode.com/problems/excel-sheet-column-number/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    static int titleToNumber(string s) {
        int total = 0;
        for(string::iterator it = s.begin(); it != s.end(); it++) {
            int num = *it - 'A' + 1;
            if(num > 26 || num < 1) {
                continue;
            }

            total = total * 26 + num;
        }
        return total;
    }
};

int main() {
    cout<<Solution::titleToNumber("AB") <<endl;
}
