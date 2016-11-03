/**
 * Url: https://leetcode.com/problems/contains-duplicate/
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            unordered_map<int, int>::iterator mit = m.find(*it);
            if(mit != m.end()) {
                return true;
            } else {
                m[*it] = 1;
            }
        }

        return false;
    }
};
