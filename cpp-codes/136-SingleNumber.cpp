/**
 * Url: https://leetcode.com/problems/single-number/
 * */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    Solution();

    static int singleNumber(vector<int>& nums) {
        int base = 0;

        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            int number = *it;
            base = (base & ~number) | (~base & number);
        }

        return base;
    }
};

int main() {
    static const int arr[] = {1};
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    cout<<Solution::singleNumber(vec)<<endl;

}
