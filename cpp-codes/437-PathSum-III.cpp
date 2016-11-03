/**
 * Url: https://leetcode.com/problems/path-sum/
 */

#include "includes/Tree.h"
#include <vector>

using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return 0;
        }
        int total = 0;
        vector<int> sumList;
        sumList.clear();
        sumList.push_back(sum);

        dfs(root, sumList, total);

        return total;
    }

    void dfs(TreeNode* root, vector<int>& sumList, int& total) {
        if(root == NULL) {
            return;
        }

        int size = sumList.size();
        sumList.push_back(sumList[size - 1]);

        for(int i = 0; i < size; i++) {
            if(root->val == sumList[i]) {
                total++;
            }
            sumList[i] = sumList[i] - root->val;
        }

        dfs(root->left, sumList, total);  
        dfs(root->right, sumList, total);

        for(int i = 0; i < size; i++) {
            sumList[i] = sumList[i] + root->val;
        }
        sumList.pop_back();
    }};

