/**
 * Url: https://leetcode.com/problems/perfect-squares/
 */

#include <iostream>
#include <queue>

using namespace std;

class Solution {

public:
    int numSquares(int n) {
        if(n <= 0) {
            return 0;
        }
        vector<int> v;
        v.push_back(1);
        for(int i = 2; i <= n; i++) {
            int min = i;
            for(int j = 1; j < n; j++) {
                if(i - j * j < 0) {
                    break;
                }
                min = minOf(min, v[i - j * j - 1] + 1);
            }
            v.push_back(min);
        }

        return v[n-1];
    }

    int minOf(int i, int j) {
        if(i > j) {
            return j;
        } else {
            return i;
        }
    }
};

int main() {
    Solution s = Solution::Solution();
    int count = s.numSquares(2);
    cout << endl;
    cout << "Count " << count << endl;
    return 0;
}
