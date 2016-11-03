#include "Tree.h"

using namespace std;

TreeNode* TreeUtils::getExampleTree() {
    TreeNode *node = new TreeNode(0);
    node->left = new TreeNode(1);
    node->right = new TreeNode(2);
    queue<TreeNode*> queue;
    queue.push(node->left);
    queue.push(node->right);
    for(int i=0; i<3; i++) {
        int size = queue.size();
        for(int j=0; j<size; j++) {
            TreeNode* child = queue.front();
            child->left = new TreeNode(i+j);
            child->right = new TreeNode(i+j+1);
            queue.pop();

            queue.push(child->left);
            queue.push(child->right);
        }
    }
    return node;
}

void TreeUtils::printTree(TreeNode* node){
    queue<TreeNode*> queue;
    cout<<"begin!"<<endl;
    queue.push(node);
    while(queue.size() > 0) {
        int size = queue.size();
        for(int i=0; i<size; i++) {
            TreeNode* child = queue.front();
            queue.pop();
            cout<<child->val<< " ";
            queue.push(child->left);
            queue.push(child->right);
        }
        cout<<endl<<"---"<<endl;
    }
    cout<<"end!"<<endl;
}

