/**
 * Url: https://leetcode.com/problems/add-digits/
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int result = 0;
        int digit = num % 10;

        cout<<"sum of " << num;
        while(num > 0) {
            num = num / 10;
            result += digit;
            digit = num % 10;
        }
        
        cout<<", result="<<result << endl;
        if(result >= 10) {
            return addDigits(result);
        } else {
            return result;
        }
    }
};


int main() {
    Solution solution = Solution::Solution();
    cout<<solution.addDigits(12333)<<endl;
}
