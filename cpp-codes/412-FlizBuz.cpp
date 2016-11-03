/**
 * Url: https://leetcode.com/problems/fizz-buzz/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<string> fizzBuzz(int n) {
        vector<string> v;
        int fizCount = 0;
        int buzCount = 0;

        for(int i = 0; i < n; i++) {
            fizCount++;
            buzCount++;
            if(fizCount == 3 && buzCount == 5) {
                v.push_back("FizzBuzz");
                fizCount = 0;
                buzCount = 0;
                continue;
            } 

            if(fizCount == 3) {
                v.push_back("Fizz");
                fizCount = 0;
                continue;
            }

            if(buzCount == 5) {
                v.push_back("Buzz");
                buzCount = 0;
                continue;
            }
            v.push_back(to_string(i + 1));
        }
        return v;
    }
};

int main() {
    vector<string> v = Solution::fizzBuzz(15);
    for(vector<string>::iterator it = v.begin();
            it != v.end();
            it++) {
        cout << *it << endl;
    }
    return 0;
}
