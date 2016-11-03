#include <iostream>
#include <cstdlib> 
#include <queue>

struct TreeNode {
    int val;

    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {};

};

class TreeUtils {

    public:
        TreeUtils();

        static TreeNode* getExampleTree();
        static void printTree(TreeNode* node);

};
