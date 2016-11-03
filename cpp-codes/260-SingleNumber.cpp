/**
 * Url: https://leetcode.com/problems/single-number-iii/
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, bool> m;
        vector<int> res;
        res.clear();

        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            unordered_map<int, bool>::iterator mit = m.find(*it);
            if(mit != m.end()) {
                mit->second = false;
            } else {
                m[*it] = true;
            }
        }

        for(unordered_map<int, bool>::iterator mit = m.begin(); mit != m.end(); mit++) {
            if(mit->second) {
                res.push_back(mit->first);
            }
        }

        return res;
    }
};
