#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class NodeUtils {
public:
    static void deleteNode(ListNode* node); 
    static void printNode(ListNode* node, int l);
    static ListNode* example(int n);
};

#endif
