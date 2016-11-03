/**
 * Url: https://leetcode.com/problems/invert-binary-tree/
 * Author : MiaoMiao&QiuQiu in sky=.=
 */

#include "includes/Tree.h"

class Solution {
public:
    static TreeNode* invertTreeNotRecursive(TreeNode* root) {
        return root;
    }

    static TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }

        if(root->left == NULL && root->right == NULL) {
            return root;
        } else {
            if(root->left == NULL) {
                root -> left = invertTree(root->right);
            } else if(root->right == NULL){
                root -> right = invertTree(root->left);
            } else {
                TreeNode* left = root->left;
                root->left = invertTree(root->right);
                root->right = invertTree(left);
            }
            return root;
        }
    }
};

int main() {
    TreeNode* node = TreeUtils::getExampleTree();
    TreeUtils::printTree(node);
    Solution::invertTree(node);
}
