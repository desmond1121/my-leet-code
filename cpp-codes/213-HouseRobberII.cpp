/**
 * Url: https://leetcode.com/problems/house-robber-ii/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(){}

    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        } 
        if(nums.size() == 1) { 
            return nums[0];
        }
        if(nums.size() == 2) {
            return maxOf(nums[0], nums[1]);
        }

        int length = nums.size() - 1;

        int rob0 = rob(nums, 0, length);
        cout << "Rob 0: " << rob0 << endl;
        int rob1 =  rob(nums, 1, length);
        cout << "Rob 1: " << rob1 << endl;
        return maxOf(rob0, rob1);
    }

private:

    int rob(vector<int>& nums, int start, int length) {
        if(length == 0) {
            return 0;
        }

        if(length == 1) {
            return nums[start];
        }

        // length >= 2
        int* record = new int[length + 1];

        for(int i = 0; i < length - 2; i++) {
            record[i] = 0;
        }

        record[length - 1] = nums[start + length - 1];
        record[length - 2] = maxOf(nums[start + length - 2], nums[start + length - 1]);

        for(int i = length - 3; i >= 0; i--) {
            record[i] = maxOf(nums[start + i] + record[i + 2], record[i + 1]);
        }

        int max = record[0];
        delete [] record;
        return max;
    }

    int maxOf(int a, int b) {
        if(a > b) {
            return a;
        } else {
            return b;
        }
    }
};

int main() {
    Solution s = Solution::Solution();
    int stash[] = {1,2,1,1};
    vector<int> stashV(stash, stash + sizeof(stash)/sizeof(stash[0]));
    int max = s.rob(stashV);
    cout << "MaxRob : " << max << endl;
}
