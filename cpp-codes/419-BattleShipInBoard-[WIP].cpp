/**
 * Url: https://leetcode.com/problems/battleships-in-a-board/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char> >& board) {
        int r = board.size();
        if(r == 0) {
            return 0;
        }
        int c = board[0].size();
        bool** avail = new bool*[r];
        for(int i = 0; i < r; i++) {
            avail[i] = new bool[c];
            for(int j = 0; j < c; j++) {
                avail[i][j] = true;
            }
        }

        int count = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(avail[i][j]) {
                    tryDetectPosotion(i, j, board, avail, count);
                }
            }
        }

        for(int i = 0; i < r; i++) {
            delete [] avail[i];
        }
        delete [] avail;
        return 0;
    }

    void tryDetectPosotion(int row, int column, vector<vector<char> >& board, bool** avail, int& count) {

    }

};
