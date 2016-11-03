/*
 * Url: https://leetcode.com/problems/sum-of-left-leaves/
 * */

#include <iostream>
#include "includes/Tree.h"

using namespace std;

class Solution {

public:

    static int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) {
            return 0;
        } 

        int total = 0;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        while(myqueue.size() > 0) {
            int size = myqueue.size();
            for(int i=0; i<size; i++) {
                TreeNode* node = myqueue.front();
                TreeNode* lc = node->left;
                if(lc != NULL && lc->left == NULL && lc->right == NULL){
                    total += lc->val;
                } else if(lc != NULL){
                    myqueue.push(lc);
                }

                if(node->right != NULL) {
                    myqueue.push(node->right);
                }

                myqueue.pop();
            }
        }
        return total;
    }

};

int main() {
    cout<<Solution::sumOfLeftLeaves(TreeUtils::getExampleTree()) << endl;
}
