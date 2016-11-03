/**
 * Url:https://leetcode.com/problems/median-of-two-sorted-arrays/
 */

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    Solution() {}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        if(l1 + l2 == 0) {
            return 0.0;
        }

        bool needAvg = ((l1 + l2) & 1) == 0;
        int m = (l1 + l2) / 2;

        int count = 0;
        double median;
        vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();

        while(true) {
            int v;
            if(it1 == nums1.end()) {
                v = *it2;
                it2++;
            } else if(it2 == nums2.end()) {
                v = *it1;
                it1++;
            } else {
                // both not end
                if(*it1 > *it2) {
                    v = *it2;
                    it2++;
                } else {
                    v = *it1;
                    it1++;
                }
            }

            if(needAvg) {
                if(count == m - 1) {
                    median = v;
                } else if(count == m) {
                    median = (median + v) / (double) 2;
                    return median;
                }
            } else {
                if(count == m) {
                    return v;
                }
            }

            count++;
        }

        return 0.0;
    }
};

int main() {
    int s1[] = {1};
    vector<int> nums1(s1, s1 + sizeof(s1) / sizeof(s1[0]));
    int s2[] = {2};
    vector<int> nums2(s2, s2 + sizeof(s2) / sizeof(s2[0]));
    Solution s = Solution::Solution();
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}
