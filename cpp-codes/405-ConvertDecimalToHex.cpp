/**
 * Url: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num == 0) {
            return "0";
        } else if(num == -1) {
            return "FFFFFFFF";
        }

        if(num > 0) {
            char res[8] = {'0'};
            int length = 0;
            while(num > 1) {
                int dec = num % 16;
                char c;
                if(dec >= 0 && dec <= 9) {
                    c = (char)(dec + '0');
                } else {
                    c = (char)(dec - 10 + 'a');
                }
                res[7 - length] = c;
                length++;
                num = num / 16;
            }

            string result = "";
            for(int i = 8 - length; i < 8; i++) {
                result += res[i];
            }
            return result;
        } else {
            string res = toHex(-(num + 1));
            string result = "";
            int length = res.length();
            for(int i = 0; i < 8 - length; i++) {
                result += 'f';
            }
            for(string::iterator it = res.begin(); it != res.end(); it++) {
                char c;
                if(*it >= '0' && *it <= '5') {
                    c = (char)('f' - (*it - '0'));
                } else {
                    int dig;
                    if(*it >= '6' && *it <= '9') {
                        dig = *it - '6';
                    } else {
                        dig = *it - 'a' + 4;
                    }
                    c = (char)('9' - dig);
                }
                result += c;
            }
            return result;
        }

    }

};

int main() {
    Solution s = Solution::Solution();
    string res = s.toHex(-1);
    cout << "res " << res << endl;
}
