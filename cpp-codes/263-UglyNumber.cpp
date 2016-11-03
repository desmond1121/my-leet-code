/**
 * Url: https://leetcode.com/problems/ugly-number/
 */

class Solution {

public:
    bool isUgly(int num) {
        if(num == 0) {
            return false;
        }
        if(num == 1 || num == 2 || num == 3 || num == 5) {
            return true;
        }

        if(num % 3 == 0) {
            return isUgly(num / 3);
        } else if(num % 5 == 0) {
            return isUgly(num / 5);
        } else if((num & 1) == 0) {
            return isUgly(num >> 1);
        }
        return false;
    }

};

