/**
 * Url: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 */
#include "includes/Tree.h"

class Solution {
    public :

        int maxDepth(TreeNode* node) {
            if(node == NULL) {
                return 0;
            }
            return maxDepthInternal(1, node);
        }

        int maxDepthInternal(int depth, TreeNode* node) {
            if(node->left == NULL
                    && node->right == NULL) {
                return depth;
            }

            if(node->left == NULL) {
                return maxDepthInternal(depth + 1, node->right);
            } else if(node->right == NULL){
                return maxDepthInternal(depth + 1, node->left);
            } else {
                int ld =maxDepthInternal(depth + 1, node->left); 
                int rd =maxDepthInternal(depth + 1, node->right); 
                if(ld > rd) {
                    return ld;
                } else {
                    return rd;
                }
            }
        }
};
