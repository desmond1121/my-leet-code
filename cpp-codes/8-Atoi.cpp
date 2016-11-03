/**
 * Url: https://leetcode.com/problems/string-to-integer-atoi/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {}

    int myAtoi(string str) {
        if(str.size() == 0) {
        	return 0;
        }

        int i = 0;
        string::iterator begin = str.begin();
        while(*begin == ' ') { // space
        	begin++;
            i++;
        	if(begin == str.end()) {
        		return 0;
        	}
        }

        bool neg = false;
        if(*begin == '-') {
        	neg = true;
        	begin++;
        } else if (*begin == '+') {
        	neg = false;
        	begin++;
        } 

        if(begin == str.end() || (*begin > '9' || *begin < '0')) {
            return 0;
        }

        string::iterator it = begin;
        int total = (*it - '0');
        if(neg) {
            total = -total;
        }
        it++;

        for(; it != str.end(); it++) {
        	if(*it > '9' || *it < '0') {
        		break;
        	}
        	int dig = *it - '0';
    		if(neg) {
    		    if(total < ((int)0x80000000 + dig) / 10) {
                    total = 0x80000000;
                    break;
                } else {
                    total = total * 10 - dig;
                }
            } else {
    		    if(total >= ((int)0x7FFFFFFF - dig) / 10) {
                    total = 0x7FFFFFFF;
                    break;
                } else {
                    total = total * 10 + dig;
                }
            }
        }

        return total;
    }
};

int main() {
    Solution solution = Solution::Solution();
    cout << solution.myAtoi("-2147483647") << endl;
    return 0;
}
