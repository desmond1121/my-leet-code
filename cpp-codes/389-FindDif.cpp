#include <iostream>

using namespace std;

/**
 * Url: https://leetcode.com/problems/find-the-difference/
 */
class Solution {
public:

    Solution();

    static char findTheDifference(string s, string t) {
        int base = (int)'a';
        int origin = 0;
        for(string::iterator it = s.begin(); it != s.end(); it++) {
            int order_of_char = (int)(*it) - base;
            origin = doXOR(origin, order_of_char);
        }
        
        for(string::iterator it = t.begin(); it != t.end(); it++) {
            int order_of_char = (int)(*it) - base;
            origin = doXOR(origin, order_of_char);
        }

        return (char) (origin + base);
    }

    static int doXOR(int a, int b) {
        return (a & ~b) | (~a & b);
    }
};

int main() {
    cout<<Solution::findTheDifference("abc", "abcd")<<endl;

}
