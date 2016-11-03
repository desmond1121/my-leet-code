/**
 * Url: https://leetcode.com/problems/n-queens/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        if(n == 1) {
            vector<string> tmp;
            tmp.push_back("Q");
            result.push_back(tmp);
            return result;
        } else if (n < 4) {
            return result;
        }

        int* rec = new int[n];
        for(int i = 0; i <= (n - 1) / 2; i++) {
            rec[0] = i;
            tryPutQueen(rec, 1, n, result);
        }

        return result;
    }

    void tryPutQueen(int* rec, int row, int n, vector<vector<string> >& result) {
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
                    reportRecord(rec, n, result);
                    return; 
                } else {
                    tryPutQueen(rec, row + 1, n, result);
                }
            }
        }
    }

    void reportRecord(int* rec, int n, vector<vector<string> >& result) {
        vector<string> tmp;
        for(int i = 0; i < n; i++) {
            tmp.push_back(constructStr(rec[i], n, false));
        }
        result.push_back(tmp);

        if(n - rec[0] - 1 != rec[0]) { // report a reversed result.
            vector<string> rev;
            for(int i = 0; i < n; i++) {
                rev.push_back(constructStr(rec[i], n, true));
            }
            result.push_back(rev);
        }
    }

    string constructStr(int index, int n, bool reverse) {
        char* c = new char[n];
        if(reverse) {
            index = n - index - 1;
        }
        for(int i = 0; i < n; i++) {
            if(i == index) {
                c[i] = 'Q';
            } else {
                c[i] = '.';
            }
        }
        return string(c, n);
    }
};

int main() {
    Solution s = Solution::Solution();
    vector<vector<string> > result = s.solveNQueens(4);
    for(vector<vector<string> >::iterator it = result.begin(); it != result.end(); it++) {
        cout<<"---"<<endl;
        for(vector<string>::iterator itc = it->begin(); itc != it->end(); itc++) {
            cout << *itc << endl;
        }
    }
    return 0;
}
