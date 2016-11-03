/**
 * Url: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 */

#include "includes/ListNode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* it = head;

        while(it != NULL && it->next != NULL) {
            if(it->next->val == it->val) {
                it->next = it->next->next;
            } else {
                it = it->next;
            }
        }

        return head;
    }
};
