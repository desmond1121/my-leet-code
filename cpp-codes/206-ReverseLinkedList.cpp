/**
 * Url: https://leetcode.com/problems/reverse-linked-list/
 */

#include "includes/ListNode.h"

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        if(!head) {
            return NULL;
        }
        ListNode* realHead = head;
        while(head->next) {
            ListNode* tmp = head->next;
            head->next = tmp->next;
            tmp->next = realHead;
            realHead = tmp;
        }
        return realHead;
    }
};
