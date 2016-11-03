/**
 * Url: https://leetcode.com/problems/happy-number/
 */
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n == 0) {
            return false;
        }
        unordered_map<int, bool> record;
        record.clear();
        return isHappyInternal(n, record);
    }

    bool isHappyInternal(int n, unordered_map<int, bool>& record) {
        if(n == 1) {
            return true;
        }
        
        unordered_map<int, bool>::iterator it = record.find(n);
        if(it != record.end()) {
            return false;
        }

        record[n] = true;

        int result = 0;
        while(n > 0) {
            int dig = n % 10;
            result += dig * dig;
            n = n / 10;
        }
        return isHappyInternal(result, record);
    }
};

int main() {
    Solution s = Solution::Solution();
    cout << s.isHappy(7) << endl;
}
