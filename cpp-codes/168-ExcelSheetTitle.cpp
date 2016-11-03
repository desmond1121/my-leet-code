/**
 * Url: https://leetcode.com/problems/excel-sheet-column-title/
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    static string convertToTitle(int n) {
        stack<char> cs;

        while(n > 0) {
            int mod = (n - 1) % 26;
            cs.push('A' + mod);
            n = (n - 1) / 26;
        }

        int length = cs.size();
        char* res = new char[length];
        for(int i=0; i<length; i++) {
            char c = cs.top();
            res[i] = c;
            cs.pop();
        }
        return string(res, length);
    }
};

int main() {
    cout<<Solution::convertToTitle(52) <<endl;
    cout<<Solution::convertToTitle(53) <<endl;
    cout<<Solution::convertToTitle(26) <<endl;
    cout<<Solution::convertToTitle(27) <<endl;
}
