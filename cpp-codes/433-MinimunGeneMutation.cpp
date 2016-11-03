/**
 * Url: https://leetcode.com/problems/minimum-genetic-mutation/
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {}

    int minMutation(string start, string end, vector<string>& bank) {
        queue<int> bfs;
        int step = 0;
        int n = bank.size();
        int minStep = n;
        bool success = false;
        bool* record = new bool[n + 1];
        for(int i = 0; i < n; i++) {
            if(canMutate(start, bank[i])) {
                bfs.push(i);
                record[i] = true;
            } else {
                record[i] = false;
            }
        }

        while(bfs.size() > 0) {
            step++;
            int size = bfs.size();
            for(int i = 0; i < size; i++) {
                string cand = bank[bfs.front()];
                if(cand.compare(end) == 0) { // end! refresh step.
                    success = true;
                    if(step < minStep) {
                        minStep = step;
                    }
                } else {  // not end, continue search.
                    for(int b = 0; b < n; b++) {
                        if(!record[b] && canMutate(cand, bank[b])) {
                            bfs.push(b);
                            record[b] = true;
                        }
                    }
                }
                bfs.pop();
            }
        }
        
        delete [] record;
        if(!success) {
            return -1;
        } else {
            return minStep;
        }
    }

private:

    bool canMutate(string a, string b) {
        if(a.size() != b.size()) {
            return false;
        }

        int count = 0;
        int n = a.size();
        for(int i = 0; i < n; i++) {

            if(b[i] != 'A' && b[i] != 'G' && b[i] != 'C' && b[i] != 'T') {
                return false;
            }

            if(a[i] != b[i]) {
                if(count > 0) {
                    return false;
                }
                count++;
            }
        }

        return true;
    }


    /* Bellowing solution encountered Runtime Error but success in my machine!!
     
    int minMutation(string start, string end, vector<string>& bank) {
        bool endInBank = false;
        for(vector<string>::iterator it = bank.begin(); it != bank.end(); it++) {
            endInBank |= end.compare(*it) == 0;
        }
        if(!endInBank) {
            return -1;
        }

        int n = bank.size();
        int* record = new int[n + 1];
        for(int i = 0; i < n; i++) {
            record[i] = -1;
        }
        int minStep = n;
        int step = 0;
        tryMutate(start, end, bank, record, step, minStep);
        
        delete []record;
        return minStep;
    }

    void tryMutate(string start, string end, vector<string>& bank, int* rec, int step, int& minStep) {
        for(int i = 0; i < bank.size(); i++) {
            bool used = false;
            for(int s = 0; s < step; s++) {
                if(rec[s] == i) {
                    used = true;
                    break;
                }
            }

            if(used) {
                continue;
            } else if(canMutate(start, bank[i])){
                     
                if(bank[i].compare(end) == 0) {
                    step = step + 1;
                    if(step < minStep) {
                        minStep = step;
                    }
                    return;
                }

                rec[step + 1] = i;
                tryMutate(bank[i], end, bank, rec, step + 1, minStep);
            }
        }
    }
    */
};

int main() {
    Solution s = Solution::Solution();
    string bank[] = {"AAAACCCA","AAACCCCA","AACCCCCA","AACCCCCC","ACCCCCCC","CCCCCCCC","AAACCCCC","AACCCCCC"};
    vector<string> bankV(bank, bank + sizeof(bank)/sizeof(bank[0]));
    string start = "AAAACCCC";
    string end = "CCCCCCCC";
    cout << "Start trying, start: " << start << " end: " << end << endl;
    int minStep = s.minMutation(start, end, bankV);
    cout << "Min step: " << minStep << endl;

    string b1[] = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    vector<string> bank1(b1, b1 + sizeof(b1)/sizeof(b1[0]));
    start = "AACCGGTT";
    end = "AAACGGTA";
    cout << "Start trying, start: " << start << " end: " << end << endl;
    minStep = s.minMutation(start, end, bank1);
    cout << "Min step: " << minStep << endl;
}
