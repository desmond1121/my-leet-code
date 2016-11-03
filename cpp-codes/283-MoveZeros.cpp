/**
 * Url: https://leetcode.com/problems/move-zeroes/
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:

    Solution();

    static void moveZeros(vector<int>& nums) {
        queue<int> cache;
        int zeroCount = 0;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if(*it != 0) {
                cache.push(*it);
            } else {
                zeroCount++;
            }
        }
        int size = nums.size();
        for(int i=0; i<size; i++) {
            if(i >= size - zeroCount) {
                nums[i] = 0;
            } else {
                nums[i] = cache.front();
                cache.pop();
            }
        }
    }

    static void swapItem(vector<int>& vec, int l, int r) {
        int left = vec[l];
        vec[l] = vec[r];
        vec[r] = left;
    }
};

int main() {
    static const int arr[] = {0, 1, 3, 0, 2, 4};
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    Solution::moveZeros(vec);

    cout<<"---"<<endl;
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<"\n---"<<endl;
}
