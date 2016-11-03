/**
 * Url: https://leetcode.com/problems/sort-list/ 
 */

#include "includes/ListNode.h"

using namespace std;

class Solution {
public:
    Solution() {}

    ListNode* sortList(ListNode* head) {
        if(!head) {
            return NULL;
        }

        if(head->next == NULL) {
            return head;
        }

        ListNode* l = NULL; 
        ListNode* m = head; 
        ListNode* r = head;


        while(r != NULL && r->next != NULL) {
            l = m;
            m = m->next;
            r = r->next->next;
        }

        l->next = NULL;

        ListNode* sl = sortList(head);
        ListNode* sr = sortList(m);

        return merge(sl, sr);
    }

    ListNode* merge(ListNode* l, ListNode* r) {
        if(!l) {
            return r;
        }

        if(!r) {
            return l;
        }

        ListNode* head;
        if(l->val < r->val) {
            head = l;
            l = l->next;
        } else {
            head = r;
            r = r->next;
        }

        ListNode* tail = head;
        while(true) {
            if(l == NULL) {
                tail->next = r;
                return head;
            } 

            if(r == NULL) {
                tail->next = l;
                return head;
            }

            if(l -> val < r->val) {
                tail->next = l;
                tail = l;
                l = l->next;
            } else {
                tail->next = r;
                tail = r;
                r = r->next;
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
    ListNode* head = new ListNode(3);
    ListNode* node = head;
    node->next = new ListNode(9);
    node = node -> next;
    node->next = new ListNode(2);
    node = node -> next;
    node->next = new ListNode(8);
    node = node -> next;
    node->next = new ListNode(4);
    node = node -> next;
    node->next = new ListNode(1);
    node = node -> next;

    ListNode* list = s.sortList(head);
    Solution::printNode(list);
    return 0;
}
