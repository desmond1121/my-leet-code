/**
 * Url: https://leetcode.com/problems/first-unique-character-in-a-string/
 */

#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    static int firstUniqChar(string s) {
        queue<int> q;
        int counts[26] = {0};
        int index = 0;

        for(string::iterator it = s.begin(); it != s.end(); it++) {
            if(counts[*it - 'a'] == 0) {
                q.push(index);
            } 

            index++;
            counts[*it - 'a']++;
        }

        while(q.size() > 0) {
            if(counts[s[q.front()] - 'a'] > 1) {
                q.pop();
            } else {
                return q.front();
            }
        }

        return -1;
    }
};

int main() {
    cout << Solution::firstUniqChar("leetcodel") << endl;
}
