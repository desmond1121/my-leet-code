/**
 * https://leetcode.com/problems/ransom-note/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    static bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() == 0) {
            return true;
        } else if(magazine.size() == 0) {
            return false;
        }

        int source[52] = {0};

        for(string::iterator it = ransomNote.begin(); it != ransomNote.end(); it++) {
            source[*it - 'a'] +=1;
        }

        int size = ransomNote.size();
        for(string::iterator it = magazine.begin(); it != magazine.end(); it++) {
            if(source[*it - 'a'] > 0) {
                size--;
                source[*it - 'a']--;
            }

            if(size == 0) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    bool result = Solution::canConstruct("asdf", "fdsaaaaa");

    if(result) {
        cout << "success!" << endl;
    } else {
        cout << "fail." << endl;
    }
}
