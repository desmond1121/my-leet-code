/**
 * Url: https://leetcode.com/problems/house-robber-iii/
 */

#include "includes/Tree.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        if(root->left == NULL && root->right == NULL) {
            return root->val;
        }

        int robThis = root->val;
        if(root->left != NULL) {
            robThis += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right != NULL) {
            robThis += rob(root->right->left) + rob(root->right->right);
        }
        int notRobThis = rob(root->left) + rob(root->right);

        return maxOf(robThis, notRobThis);
    }

private:
    int maxOf(int a, int b) {
        if(a > b) {
            return a;
        } else {
            return b;
        }
    }
};
