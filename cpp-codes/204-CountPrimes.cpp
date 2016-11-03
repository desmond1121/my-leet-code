/**
 * Url: https://leetcode.com/problems/count-primes/
 */
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {}

    int countPrimes(int n) {
        if(n < 2) {
            return 0;
        }

        bool* isPrime = new bool[n];
        for(int i = 0; i < n; i++) {
            if(i < 2) {
                isPrime[i] = false;
            } else {
                isPrime[i] = true;
            }
        }

        for(int i = 2; i <= n / 2; i++) {
            if(!isPrime[i]) {
                continue;
            }

            int index = i * 2;
            while(index < n) {
                isPrime[index] = false;
                index += i;
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(isPrime[i]) {
                count++;
                cout << i << endl;
            }
        }
        return count;
    }
};

int main() {
    Solution s = Solution::Solution();
    s.countPrimes(5);
}
