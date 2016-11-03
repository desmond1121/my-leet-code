/**
 * Url: https://leetcode.com/problems/n-queens-ii/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int totalNQueens(int n) {
        if(n == 1) {
            return 1;
        } else if (n < 4) {
            return 0;
        }

        int total = 0;
        int* rec = new int[n];
        for(int i = 0; i <= (n - 1) / 2; i++) {
            rec[0] = i;
            tryPutQueen(rec, 1, n, total);
        }

        return total;
    }

    void tryPutQueen(int* rec, int row, int n, int& total) {
        for(int j = 0; j < n; j++) {
            bool invalid = false;
            for(int k = 0; k < row; k++) {
                if(rec[k] == j) {
                    invalid = true;
                    break;
                }

                if(j - rec[row - k - 1] == (k + 1) || rec[row - k - 1] - j == (k + 1)) {
                    invalid = true;
                    break;
                }
            }

            if(invalid) {
                if(j == n - 1) { 
                    return; // Queen cannot be places in input record!
                }
                continue;
            } else {
                rec[row] = j;
                if(row + 1 == n) {
                    reportRecord(rec, n, total);
                    return; 
                } else {
                    tryPutQueen(rec, row + 1, n, total);
                }
            }
        }
    }

    void reportRecord(int* rec, int n, int& total) {
        total++;

        if(n - rec[0] - 1 != rec[0]) { // report a reversed result.
            total++;
        }
    }

};

int main() {
    Solution s = Solution::Solution();
    int n = 4;
    cout << n << " queens solution count: " << s.totalNQueens(n) << endl;
    return 0;
}
