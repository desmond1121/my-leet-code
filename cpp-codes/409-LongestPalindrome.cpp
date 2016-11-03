/*
 * Url: https://leetcode.com/problems/longest-palindrome/
 */

#include <iostream>
#include <map>
using namespace std;

class Solution {

public:

    static int longestPalindrome(string src) {
        map<char, int> charMap;
        int longest = 0;
        int probably = 0;
        for(string::iterator it = src.begin(); it != src.end();  it++) {
            if(charMap[*it] > 0) {
                longest += 2;
                probably--;
                charMap[*it] = 0;
            } else{
                charMap[*it] = 1;
                probably++;
            }
        }
        if(probably > 0) {
            return longest + 1;
        } else {
            return longest;
        }
    }

};

int main() {
    cout<<Solution::longestPalindrome("abccccdd") << endl;
}
