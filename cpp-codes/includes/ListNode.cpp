#include "ListNode.h"

using namespace std;
/**
 * Url: https://leetcode.com/problems/delete-node-in-a-linked-list/
 */
static ListNode* example(int n) {
    ListNode* head = new ListNode(1);
    ListNode* node = head;
    for(int i = 0; i < n; i++) {
        node->next = new ListNode(i + 2);
        node = node->next;
    }
    return head;
}
void NodeUtils::deleteNode(ListNode* node) {
    if(node->next == NULL) {
        node = NULL;
    } else {
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
        next->next = NULL;
    }
}

void printNode(ListNode* node, int l) {
    int count = 0;
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
        count++;
        if(l > 0 && count >= l) {
            break;
        }
    }
    cout << endl;
}
