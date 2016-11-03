/**
 * Url: https://leetcode.com/problems/ugly-number-ii/
 * C++ Solusion would encounter different result!
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) {
            return 1;
        }
        vector<bool> rec;
        rec.clear();
        rec.push_back(true);
        int count = 1;
        int candidate = 1;
        while(count < n) {
            candidate++;
            if(isUgly(candidate, rec)) {
                rec.push_back(true);
                count++;
            } else {
                rec.push_back(false);
            }
        }
        cout << "Input : " << n << " => " << candidate << endl;
        return candidate;
    }

private:
    bool isUgly(int n, vector<bool>& v) {
        if(n == 1 || n == 2 || n == 3 || n == 4 || v[n - 1]) {
            return true;
        }

        if((n & 1) == 0) {
            return isUgly(n >> 1, v);
        } else if(n % 3 == 0) {
            return isUgly(n / 3, v);
        } else if(n % 5 == 0) {
            return isUgly(n / 5, v);
        }
        return false;
    }
};

int main() {
    Solution s = Solution::Solution();
    for(int i = 2; i < 100; i++) {
        s.nthUglyNumber(i);
        s.nthUglyNumber(i);
    }
    return 0;
}
