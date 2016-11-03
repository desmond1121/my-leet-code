/**
 * Url: https://leetcode.com/problems/majority-element/
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> m;

        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            unordered_map<int, int>::iterator mit = m.find(*it);
            if(mit != m.end()) {
                if(mit->second + 1 > size / 2) {
                    return *it;
                }
                mit->second = mit->second + 1;
            } else {
                if(1 > size / 2) {
                    return *it;
                }
                m[*it] = 1;
            }
        }
        return 0;
    }

    // Use Moore's Vote Algorithm
    int majorityElementMoore(vector<int>& nums) {
        if(nums.size() < 3) {
            return nums[0];
        }

        int m = 0;
        int size = nums.size();
        int count = 0;

        for(int i = 0; i < size; i++) {
            if(count == 0) {
                m = nums[i];
                count++;
            } else if(m != nums[i]) {
                count--;
            } else {
                count++;
            }
            cout << count << " " << m << endl;
        }

        return m;
    }
};

int main() {
    int arr[] = {3, 3, 4};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    Solution s = Solution::Solution();
    cout << s.majorityElementMoore(v) << endl;
}
