#include <iostream>

/* 
 * c | a | b => sum | c
 * 0 | 0 | 0 =>  0    0
 * 0 | 0 | 1 =>  1    0
 * 0 | 1 | 0 =>  1    0
 * 0 | 1 | 1 =>  0    1
 * 1 | 0 | 0 =>  1    0
 * 1 | 0 | 1 =>  0    1
 * 1 | 1 | 0 =>  0    1
 * 1 | 1 | 1 =>  1    1
 */
class Solution {
public:

    int getSumOfDistraction(int a, int b) {
        if(a > b) {
            return 1;
        } else if(a == b) {
            return 0;
        } else {
            return -getSumOfDistraction(b, a);
        }
    }

    int getSumOfTwoPositive(int a, int b) {
        int bitOffset = 0;
        size_t sum = 0;
        int tmp_a = a;
        int tmp_b = b;
        int carry = 0;
        while (tmp_a > 0 || tmp_b > 0) {

            std::cout<< "---" <<std::endl;
            std::cout<< "tmp:" << tmp_a << " " << tmp_b << std::endl;

            int bit_a = tmp_a & 1;
            int bit_b = tmp_b & 1;
            int tmp_sum = 0;

            std::cout<< "bit:" << bit_a << " " << bit_b << ", carry:" << carry << std::endl;

            if(bit_a == bit_b) {
                tmp_sum = carry;
            } else {
                tmp_sum = 1 - carry;
            }
            if(carry == 0) {
                carry = bit_a & bit_b;
            } else {
                carry = bit_a | bit_b;
            }

            std::cout<< "tmp_sum:" << tmp_sum << ", carry: " << carry << std::endl;

            sum = sum | (tmp_sum << bitOffset);

            std::cout<< "sum: " << sum << std::endl;

            if(tmp_a > 0) {
                tmp_a = tmp_a >> 1;
            }

            if(tmp_a < 0) {
                tmp_a = 0;
            }

            if(tmp_b > 0) {
                tmp_b = tmp_b >> 1;
            }

            if(tmp_b < 0) {
                tmp_b = 0;
            }

            bitOffset++;
        }

        if(carry == 1) {
            sum = sum | (carry << bitOffset);
        }
        return sum;
    }

    
};

int main() {
    Solution solution = Solution::Solution();
    std::cout<<solution.getSum(-1, 1);
}
