/**
 * Url: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int length = nums.size();
        int total = nums.size();
        int count = 0;
        int curr;
        for(vector<int>::reverse_iterator it = nums.rbegin(); it != nums.rend(); it++) {
            if(count == 0) {
                curr = *it;
            } else if(*it == curr) {
                length--;
                nums.erase(nums.begin() + total - 1 - count);
            } else {
                curr = *it;
            }
            count++;
        }
        return length;
    }
};