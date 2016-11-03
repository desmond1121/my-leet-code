/**
 * Url: https://leetcode.com/problems/swap-nodes-in-pairs/
 */

#include "includes/ListNode.h"

using namespace std;

class Solution {
public:
    Solution() {}

    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }

        ListNode* h = head;
        if(head->next != NULL) {
            h = head->next;
            head->next = h->next;
            h->next = head;
        } else {
            return head;
        }

        while(head->next != NULL && head->next->next != NULL) {
            ListNode* n1 = head->next;
            ListNode* n2 = n1->next;
            ListNode* next = n2->next;

            head->next = n2;
            n2->next = n1;
            n1->next = next;
            head = n1;
        }
        return h;
    }
};

ListNode* example(int n) {
    ListNode* head = new ListNode(1);
    cout << "1 ";
    ListNode* node = head;
    for(int i = 1; i < n; i++) {
        cout << (i + 1) << " ";
        node->next = new ListNode(i + 1);
        node = node->next;
    }
    cout << endl;
    return head;
}

int main() {
    Solution s = Solution::Solution();
    s.swapPairs(example(4));
    return 0;
}
