/**
 * Url: https://leetcode.com/problems/counting-bits/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {}
    vector<int> countBits(int num) {
        vector<int> v;
        if(num == 0) {
            v.push_back(0);
            return v;
        } if(num == 1) {
            v.push_back(0);
            v.push_back(1);
            return v;
        }

        int* rec = new int[num + 1];
        rec[0] = 0;
        rec[1] = 1;
        int count = 0;

        for(int i = 2; i <= num; i++) {
            if(isPowerOfTwo(i)) { // num is power of 2
                count = 0;
                rec[i] = 1;
            } else {
                count++;
                rec[i] = rec[count] + 1;
            }
        }

        for(int i = 0; i <= num; i++) {
            v.push_back(rec[i]);
        }
        return v;
    }

private:
    bool isPowerOfTwo(int i) {
        return !(i&(i-1));
    }
};

int main() {
    Solution s = Solution::Solution();
    s.countBits(10);
}
