/**
 * Url: https://leetcode.com/problems/intersection-of-two-arrays/
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, bool> mymap;

        for(vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++) {
            if(mymap[*it]) {
                continue;
            } else {
                mymap[*it] = true;
            }
        }

        for(vector<int>::iterator it = nums2.begin(); it != nums2.end(); it++) {
            if(!mymap[*it]) {
                continue;
            } else {
                mymap[*it] = false;
                result.push_back(*it);
            }
        }
        return result;
    }
};
