/**
 * Url: https://leetcode.com/problems/intersection-of-two-arrays-ii/
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int c = n;
        if(n > m) {
            c = m;
        }

        unordered_map<int, int> set = unordered_map<int, int>(c);
        vector<int> res = vector<int>(c);
        if(n > m) {
            doIntersect(nums2, nums1, set, res);
        } else {
            doIntersect(nums1, nums2, set, res);
        }

        return res;
    }

    void doIntersect(vector<int>& first, vector<int>& sec, unordered_map<int, int>& set, vector<int>& res) {

        for(vector<int>::iterator it = first.begin(); it != first.end(); it++) {
            unordered_map<int, int>::iterator mit = set.find(*it);
            if(mit != set.end()) {
                mit->second++;
            } else {
                set[*it] = 1;
            }
        }

        for(vector<int>::iterator it = sec.begin(); it != sec.end(); it++) {
            unordered_map<int, int>::iterator mit = set.find(*it);
            if(mit != set.end() && mit->second > 0) {
                res.push_back(*it);
                mit->second--;
            }             
        }
    }
};
