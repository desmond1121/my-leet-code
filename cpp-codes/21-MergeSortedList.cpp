/**
 * Url: https://leetcode.com/problems/sort-list/ 
 */

#include "includes/ListNode.h"

using namespace std;

class Solution {
public:
    Solution() {}

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) {
            return l2;
        }

        if(!l2) {
            return l1;
        }

        ListNode* head;
        if(l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }

        ListNode* tail = head;
        while(true) {
            if(l1 == NULL) {
                tail->next = l2;
                return head;
            } 

            if(l2 == NULL) {
                tail->next = l1;
                return head;
            }

            if(l1 -> val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
    }

    static void printNode(ListNode* node) {
        while(node != NULL) {
            cout << node->val;
            cout << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main() {
    Solution s = Solution::Solution();
    ListNode* l1 = new ListNode(3);
    ListNode* node = l1;
    node->next = new ListNode(9);
    node = node -> next;
    node->next = new ListNode(2);

    ListNode* l2 = new ListNode(3);
    node = l2;
    node->next = new ListNode(8);
    node = node -> next;
    node->next = new ListNode(4);
    node = node -> next;
    node->next = new ListNode(1);

    ListNode* list = s.mergeTwoLists(l1, l2);
    Solution::printNode(list);
    return 0;
}
