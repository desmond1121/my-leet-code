/**
 * Url: https://leetcode.com/problems/valid-anagram/
 */
#include <iostream>

using namespace std;

class Solution {
public:
    static bool isAnagram(string s, string t) {

        if(s.size() != t.size()) {
            return false;
        }
        
        int* arrayMap = new int[s.size() + 1];
        int size = s.size();
        for(int i = 0; i < size; i++) {
            arrayMap[i] = 0;
        }
        
        bool result = true;
        
        for(string::iterator it = s.begin(); it != s.end(); it++) {
            arrayMap[*it - 'a'] += 1;
        }
        
        for(string::iterator it = t.begin(); it != t.end(); it++) {
            if(arrayMap[*it - 'a'] == 0) {
                result = false;
                break;
            }

            arrayMap[*it - 'a'] -= 1;
        }
        
        delete [] arrayMap;
        return result;

    }
};

int main() {
    cout << Solution::isAnagram("hqbqo", "lsnma") << endl;
}
