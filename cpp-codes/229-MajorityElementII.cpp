/**
 * Url: https://leetcode.com/problems/majority-element-ii/ 
 */

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int vote[2] = {0};
        int majority[2] = {0};
        int size = nums.size();

        for(int i = 0; i < size; i++) {
            appendItem(vote, majority, nums[i]);
        }

        vector<int> v;
        int count1 = 0; 
        int count2 = 0;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if(vote[0] > 0 && *it == majority[0]) {
                count1++;
            } else if(vote[1] > 0 && *it == majority[1]) {
                count2++;
            }
        }
        if(count1 > nums.size() / 3) {
            v.push_back(majority[0]);
        }
        if(count2 > nums.size() / 3) {
            v.push_back(majority[1]);
        }
        return v;
    }
    
private: 
    void appendItem(int* vote, int* majority, int num) {
        if(num == majority[0]) {
            vote[0]++;
        } else if(num == majority[1]) {
            vote[1]++;
        } else if(vote[0] == 0) {
            vote[0] = 1;
            majority[0] = num;
        } else if(vote[1] == 0) {
            vote[1] = 1;
            majority[1] = num;
        } else {
            vote[0]--;
            vote[1]--;
        }
    }
};


int main() {
    int arr[] = {4, 5, 4, 5, 4, 4, 5, 6, 6, 6, 6};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    Solution s = Solution::Solution();
    s.majorityElement(v);
}
