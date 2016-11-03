/**
 * Url: https://leetcode.com/problems/climbing-stairs/
 */

#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) {
            return 1;
        }
        int step1 = 1;
        int step2 = 2;
        int step = step2;
        for(int i = n - 3; i >= 0; i--) {
            step = step1 + step2;
            step1 = step2;
            step2 = step;
        }
        return step;
    }
};
